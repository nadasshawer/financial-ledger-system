#include "../../include/core/registration.h"
#include "../../include/auth/user_info.h"
#include "../../include/validation/validation.h"
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>

extern UserInfo newUser;

void registerUser() {
    using namespace ftxui;

    // Start with EMPTY strings so there is no pre-filled data
    std::string f_name, l_name, p_word, error_msg, final_username;
    std::string day_str = "", year_str = ""; 
    int month_idx = 0;
    bool show_success = false;

    std::vector<std::string> month_options = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    // Use the second argument of Input() for the placeholder/hint
    Component input_f = Input(&f_name, "Enter First Name...");
    Component input_l = Input(&l_name, "Enter Last Name...");
    Component input_d = Input(&day_str, "DD");
    Component input_y = Input(&year_str, "YYYY");
    auto month_menu = Dropdown(&month_options, &month_idx);
    
    InputOption pass_opt; pass_opt.password = true;
    Component input_p = Input(&p_word, "••••••••", pass_opt);

    // MOUSE SUPPORT: ScreenInteractive::TerminalOutput() usually handles it,
    // but we ensure the Loop is clean.
    auto screen = ScreenInteractive::TerminalOutput();

    auto btn = Button(" REGISTER ACCOUNT ", [&] {
        std::string feedback = getPasswordFeedback(p_word);
        if (f_name.empty() || l_name.empty() || day_str.empty() || year_str.empty()) {
            error_msg = "Error: All fields are required!";
        } else if (feedback != "VALID") {
            error_msg = feedback; 
        } else {
            final_username = (char)tolower(f_name[0]) + l_name + year_str;
            newUser.setUsername(final_username);
            show_success = true; 
        }
    });

    auto exit_btn = Button(" PROCEED TO LOGIN ", [&] { screen.Exit(); });

    auto layout = Container::Vertical({ input_f, input_l, month_menu, input_d, input_y, input_p, btn, exit_btn });

    auto renderer = Renderer(layout, [&] {
        if (show_success) {
            return vbox({
                text(" REGISTRATION COMPLETE ") | bold | center | color(Color::Green),
                separator(),
                text("Welcome to FLUX, " + f_name + "!") | center,
                text("Your unique identity is: ") | center,
                text(" " + final_username + " ") | bold | center | bgcolor(Color::Cyan1) | color(Color::Black),
                separator(),
                exit_btn->Render() | center | color(Color::Green)
            }) | borderHeavy | color(Color::Green) | center;
        }

        return vbox({
            text(" F L U X ") | bold | center | color(Color::DeepSkyBlue1),
            vbox({
                text(" NEW REGISTRATION ") | bold | center,
                separator(),
                hbox(text(" FIRST: "), input_f->Render() | flex) | border,
                hbox(text(" LAST:  "), input_l->Render() | flex) | border,
                
                text(" BIRTH DATE ") | dim | center,
                hbox({
                    month_menu->Render() | size(WIDTH, EQUAL, 10),
                    separator(),
                    text(" DAY: "), input_d->Render() | size(WIDTH, EQUAL, 5),
                    separator(),
                    text(" YEAR: "), input_y->Render() | size(WIDTH, EQUAL, 8)
                }) | border,

                hbox(text(" PASS:  "), input_p->Render() | flex) | border,
                text(error_msg) | color(Color::Red1) | center,
                btn->Render() | center | bgcolor(Color::DeepSkyBlue1) | color(Color::White)
            }) | borderHeavy | color(Color::DeepSkyBlue1) | size(WIDTH, LESS_THAN, 60)
        }) | center;
    });

    screen.Loop(renderer);
}