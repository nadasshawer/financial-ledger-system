#include "../../include/core/login.h"
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>

bool loginUser() {
    using namespace ftxui;

    std::string u_name, p_word;
    bool success = false;
    auto screen = ScreenInteractive::TerminalOutput();

    Component input_u = Input(&u_name, "Your Username");
    InputOption pass_opt; pass_opt.password = true;
    Component input_p = Input(&p_word, "••••••••", pass_opt);

    auto btn = Button(" ACCESS SYSTEM ", [&] { 
        success = true; 
        screen.Exit(); 
    });

    auto layout = Container::Vertical({ input_u, input_p, btn });

    auto renderer = Renderer(layout, [&] {
        return vbox({
            text(" F L U X ") | bold | center | color(Color::DeepSkyBlue1),
            vbox({
                text(" LOGIN ") | bold | center,
                separator(),
                hbox(text(" USERNAME: "), input_u->Render() | flex) | border,
                hbox(text(" PASSWORD: "), input_p->Render() | flex) | border,
                text(""),
                btn->Render() | center | bgcolor(Color::DeepSkyBlue1) | color(Color::White)
            }) | borderHeavy | color(Color::DeepSkyBlue1) | size(WIDTH, LESS_THAN, 50)
        }) | center;
    });

    screen.Loop(renderer);
    return success; // Returns true after the screen closes
}