#pragma once

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800 

#define GAME_TITLE "Conway's Game Of Life"

#define PATH_PRESET_GLIDER_GUN "../assets/presets/GliderGun.txt"
#define PATH_PRESET_SYMMETRY_ACORN "../assets/presets/SymmetryAcorn.txt"
#define PATH_PRESET_B_HEPTOMINO "../assets/presets/B-Heptomino.txt"

#define PATH_MOULDY_FONT "../assets/fonts/MouldyCheeseRegular.ttf"

#define GAMESTATE_BACKGROUND_COLOR sf::Color::Black
#define GAMESTATE_TEXT_NORMAL_COLOR sf::Color::White
#define GAMESTATE_TEXT_ACTIVE_COLOR sf::Color::Red

#define PATH_SPLASH_BACKGROUND "../assets/res/SplashBackground.png"
#define SPLASHSTATE_DELAY_SECONDS 1.0f

#define BOARD_ROWS 50 
#define BOARD_COLUMNS 50
#define BOARD_MARGIN 50.0f

#define GENERATION_DELAY_SECONDS 0.005f

#define CELL_WIDTH (SCREEN_WIDTH-(2*BOARD_MARGIN))/BOARD_ROWS
#define CELL_HEIGHT (SCREEN_HEIGHT-(2*BOARD_MARGIN))/BOARD_COLUMNS
#define CELL_OUTLINE_THICKNESS 1.0f
#define CELL_ALIVE_FILL_COLOR sf::Color::Green
#define CELL_DEAD_FILL_COLOR sf::Color::Black
#define CELL_OUTLINE_COLOR sf::Color::White
