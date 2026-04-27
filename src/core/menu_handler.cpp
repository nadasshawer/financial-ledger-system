#include "../../include/core/menu_handler.h"
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/dom/table.hpp> 
#include <vector>
#include <string>
#include <iomanip> 
#include <sstream>

struct Transaction { std::string type; std::string source; double amount; };
std::vector<Transaction> session_history; 
double total_in = 0.0, total_out = 0.0;
int current_view = 0; 

std::string formatCurrency(double amount) {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << amount;
    return "$" + ss.str();
}

void chooseTracker() {
    using namespace ftxui;
    auto screen = ScreenInteractive::TerminalOutput();

    // We need unique strings for EACH tracker so they don't overwrite
    std::string rev_amt = "", rev_src = "";
    std::string exp_amt = "", exp_src = "";

    // --- MAIN MENU ---
    int menu_selected = 0;
    std::vector<std::string> menu_entries = { " 💰 REVENUE TRACKER ", " 💸 EXPENSE TRACKER ", " 📊 VIEW LEDGER " };
    auto main_menu = Menu(&menu_entries, &menu_selected);
    auto btn_launch = Button(" OPEN TRACKER ", [&] { current_view = menu_selected + 1; });

    // --- REVENUE TRACKER COMPONENTS ---
    auto in_rev_src = Input(&rev_src, "Source...");
    auto in_rev_amt = Input(&rev_amt, "0.00");
    auto btn_rev_commit = Button(" COMMIT ", [&] {
        if(!rev_amt.empty()){
            try {
                double val = std::stod(rev_amt);
                session_history.push_back({"INCOME", rev_src, val});
                total_in += val;
                rev_amt = ""; rev_src = ""; 
            } catch (...) {}
        }
    });

    // --- EXPENSE TRACKER COMPONENTS ---
    auto in_exp_src = Input(&exp_src, "Category...");
    auto in_exp_amt = Input(&exp_amt, "0.00");
    auto btn_exp_commit = Button(" COMMIT ", [&] {
        if(!exp_amt.empty()){
            try {
                double val = std::stod(exp_amt);
                session_history.push_back({"EXPENSE", exp_src, val});
                total_out += val;
                exp_amt = ""; exp_src = ""; 
            } catch (...) {}
        }
    });

    // SHARED BACK BUTTON
    auto btn_back = Button(" BACK ", [&] { 
        current_view = 0; 
        screen.PostEvent(Event::Custom); 
    });

    // --- INDEPENDENT CONTAINERS ---
    auto revenue_logic = Container::Vertical({
        in_rev_src, in_rev_amt, 
        Container::Horizontal({btn_rev_commit, btn_back})
    });

    auto expense_logic = Container::Vertical({
        in_exp_src, in_exp_amt, 
        Container::Horizontal({btn_exp_commit, btn_back})
    });

    auto main_tabs = Container::Tab({
        Container::Vertical({ main_menu, btn_launch }),   
        revenue_logic, 
        expense_logic, 
        Container::Vertical({ btn_back })   
    }, &current_view);

    auto final_component = CatchEvent(main_tabs, [&](Event event) {
        if (event == Event::Character('q')) { screen.Exit(); return true; }
        if (event == Event::Escape) { current_view = 0; return true; }
        return false;
    });

    auto renderer = Renderer(final_component, [&] {
        Element content;

        if (current_view == 0) {
            content = vbox({
                text("  MAIN NAVIGATION ") | bold | color(Color::MediumPurple1),
                text(""),
                main_menu->Render() | color(Color::Cyan1),
                text(""),
                btn_launch->Render() | center | bgcolor(Color::DeepSkyBlue1) | color(Color::White)
            });
        } 
        else if (current_view == 1 || current_view == 2) {
            bool isRev = (current_view == 1);
            Color theme = isRev ? Color::Cyan1 : Color::MediumPurple1;
            content = vbox({
                text(" TRACKER: " + std::string(isRev ? "REVENUE" : "EXPENSE")) | bold | color(theme),
                text(""),
                hbox(text("  DESC : "), (isRev ? in_rev_src : in_exp_src)->Render() | flex) | border | color(theme),
                hbox(text("  AMT  : "), (isRev ? in_rev_amt : in_exp_amt)->Render() | flex) | border | color(theme),
                text(""),
                hbox({
                    (isRev ? btn_rev_commit : btn_exp_commit)->Render() | flex | bgcolor(theme) | color(Color::Black),
                    text("  "), 
                    btn_back->Render() | flex | bgcolor(Color::GrayDark) | color(Color::White)
                })
            });
        } 
        else {
            std::vector<std::vector<Element>> rows = {{text(" TYPE "), text(" DESC "), text(" AMT ") | align_right}};
            for (auto& t : session_history) {
                rows.push_back({
                    text(t.type) | color(t.type == "INCOME" ? Color::Cyan1 : Color::MediumPurple1),
                    text(" " + t.source), text(formatCurrency(t.amount)) | align_right
                });
            }
            auto table = Table(rows);
            table.SelectAll().Border(LIGHT);
            table.SelectColumn(1).Decorate(flex);
            content = vbox({
                text(" FINANCIAL AUDIT ") | bold | color(Color::Cyan1),
                text(""), table.Render(), text(""),
                hbox(text(" BALANCE: "), filler(), text(formatCurrency(total_in - total_out)) | bold),
                text(""), btn_back->Render() | center | bgcolor(Color::DeepSkyBlue1) | color(Color::White)
            });
        }

        return vbox({
            text(" F L U X   S Y S T E M S ") | bold | center | color(Color::DeepSkyBlue1),
            text("────────────────────────────────────────────────") | center | color(Color::DeepSkyBlue1),
            text(""),
            vbox({
                text(""), hbox({ text("  "), content | flex, text("  ") }), text(""),
            }) | borderHeavy | color(Color::DeepSkyBlue1) | size(WIDTH, EQUAL, 60),
            text(""),
            text(" [TAB] MOVE | [ESC] MENU | [Q] EXIT ") | dim | center
        }) | center;
    });

    screen.Loop(renderer);
}