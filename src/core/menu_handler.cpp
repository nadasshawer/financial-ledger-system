/**
 - @file menu_handler.cpp
 - @brief Full navigation logic for FLUX Trackers.
 */

#include "../../include/core/menu_handler.h"
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <vector>
#include <string>
#include <iostream>

// Placeholder function declarations so the switch works
void showIncomeTracker();
void showExpenseTracker();
void showTaxCalculator();

void chooseTracker() {
    using namespace ftxui;

    int selected = 0;
    std::vector<std::string> options = {
        "  [1] INCOME TRACKER    ",
        "  [2] EXPENSE TRACKER   ",
        "  [3] TAX CALCULATOR    ",
        "  [4] EXIT SYSTEM       "
    };

    auto screen = ScreenInteractive::TerminalOutput();
    auto menu = Menu(&options, &selected);

    // The logic that triggers when you click the button
    auto btn = Button(" LAUNCH MODULE ", [&] {
        switch (selected) {
            case 0: // Income Tracker
                showIncomeTracker();
                break;
            case 1: // Expense Tracker
                showExpenseTracker();
                break;
            case 2: // Tax Calculator
                showTaxCalculator();
                break;
            case 3: // Exit
                exit(0);
                break;
        }
    });

    auto layout = Container::Vertical({
        menu,
        btn,
    });

    auto renderer = Renderer(layout, [&] {
        return vbox({
            // Header Bar
            text(" F L U X   S Y S T E M S ") | bold | center | bgcolor(Color::DeepSkyBlue1) | color(Color::White),
            
            separator(),
            
            text(""), 
            hbox({
                text("  "), 
                vbox({
                    text(" CHOOSE YOUR TRACKER: ") | bold | color(Color::Cyan1),
                    text(" Use arrow keys or mouse to select destination. ") | dim,
                    text(""),
                    menu->Render() | color(Color::Cyan1) | borderRounded,
                }) | flex,
                text("  "), 
            }),
            text(""), 

            separator(),

            // Footer
            text(" System Status: Online ") | dim | center,
            btn->Render() | center | bgcolor(Color::DeepSkyBlue1) | color(Color::White),
            text("")
        }) | borderHeavy | color(Color::DeepSkyBlue1) | center;
    });

    screen.Loop(renderer);
}

// --- MODULE PLACEHOLDERS (So the code works immediately) ---

void showIncomeTracker() {
    using namespace ftxui;
    auto screen = ScreenInteractive::TerminalOutput();
    auto btn = Button(" BACK TO NAVIGATOR ", [&] { screen.Exit(); });
    
    auto renderer = Renderer(btn, [&] {
        return vbox({
            text(" INCOME TRACKER MODULE ") | bold | center | color(Color::Green),
            separator(),
            text(" [ Module is under construction... ] ") | center,
            text(" Here you will log your BCIT scholarship or job income! ") | dim | center,
            text(""),
            btn->Render() | center
        }) | borderHeavy | color(Color::Green) | center;
    });
    screen.Loop(renderer);
}

void showExpenseTracker() {
    using namespace ftxui;
    auto screen = ScreenInteractive::TerminalOutput();
    auto btn = Button(" BACK TO NAVIGATOR ", [&] { screen.Exit(); });
    
    auto renderer = Renderer(btn, [&] {
        return vbox({
            text(" EXPENSE TRACKER MODULE ") | bold | center | color(Color::Red1),
            separator(),
            text(" [ Module is under construction... ] ") | center,
            text(" Tracking your coffee and tuition spending. ") | dim | center,
            text(""),
            btn->Render() | center
        }) | borderHeavy | color(Color::Red1) | center;
    });
    screen.Loop(renderer);
}

void showTaxCalculator() {
    using namespace ftxui;
    auto screen = ScreenInteractive::TerminalOutput();
    auto btn = Button(" BACK TO NAVIGATOR ", [&] { screen.Exit(); });
    
    auto renderer = Renderer(btn, [&] {
        return vbox({
            text(" TAX CALCULATOR MODULE ") | bold | center | color(Color::Yellow),
            separator(),
            text(" [ Module is under construction... ] ") | center,
            text(" Calculating CRA tax brackets for BC. ") | dim | center,
            text(""),
            btn->Render() | center
        }) | borderHeavy | color(Color::Yellow) | center;
    });
    screen.Loop(renderer);
}