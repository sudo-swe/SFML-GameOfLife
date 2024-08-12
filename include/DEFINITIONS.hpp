#pragma once

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800 

#define GAME_TITLE "Conway's Game Of Life"

#define PATH_PRESET_GLIDER_GUN "../assets/presets/GliderGun.txt"
#define PATH_PRESET_SYMMETRY_ACORN "../assets/presets/SymmetryAcorn.txt"
#define PATH_PRESET_B_HEPTOMINO "../assets/presets/B-Heptomino.txt"

#define PATH_MOULDY_FONT "../assets/fonts/MouldyCheeseRegular.ttf"

#define PATH_MENUSTATE_BACKGROUND "../assets/res/MenuBackground.png"

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
#define CELL_ALIVE_RANDOM_COLOR_1 sf::Color(250, 221, 35)
#define CELL_ALIVE_RANDOM_COLOR_2 sf::Color(35, 250, 232)
#define CELL_ALIVE_RANDOM_COLOR_3 sf::Color(35, 250, 39)
#define CELL_ALIVE_RANDOM_COLOR_4 sf::Color(35, 35, 250)
#define CELL_ALIVE_RANDOM_COLOR_5 sf::Color(211, 35, 250)
#define CELL_ALIVE_RANDOM_COLOR_6 sf::Color(250, 153, 35)
#define CELL_DEAD_FILL_COLOR sf::Color::Black
#define CELL_DEAD_TRAIL_1 sf::Color(190, 0, 0)
#define CELL_DEAD_TRAIL_2 sf::Color(150, 0, 0)
#define CELL_DEAD_TRAIL_3 sf::Color(120, 0, 0)
#define CELL_DEAD_TRAIL_4 sf::Color(100, 0, 0)
#define CELL_DEAD_TRAIL_5 sf::Color(80, 0, 0)
#define CELL_DEAD_TRAIL_6 sf::Color(70, 0, 0)
#define CELL_DEAD_TRAIL_7 sf::Color(60, 0, 0)
#define CELL_DEAD_TRAIL_8 sf::Color(50, 0, 0)
#define CELL_DEAD_TRAIL_9 sf::Color(30, 0, 0)
#define CELL_DEAD_TRAIL_10 sf::Color(15, 0, 0)
#define CELL_DEAD_TRAIL_11 sf::Color(0, 0, 0)
#define CELL_OUTLINE_COLOR sf::Color::White
