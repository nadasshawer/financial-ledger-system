#ifndef TUI_PALETTE_H
#define TUI_PALETTE_H

/**
 - @file tui_palette.h
 - @brief defines the color theme for the flux systems engine.
 - @details uses ansi escape codes to apply custom pink, purple, and mint styling.
 */

// color definitions
#define RESET        "\033[0m"
#define BOLD         "\033[1m"
#define CLEAR_SCREEN "\033[2J\033[H"

// user's custom aesthetic
#define FLUX_PINK    "\033[38;5;211m" 
#define FLUX_PURPLE  "\033[38;5;141m"
#define FLUX_MINT    "\033[38;5;121m"
#define FLUX_ORANGE  "\033[38;5;215m"

#endif