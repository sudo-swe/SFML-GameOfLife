#pragma once

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800 

#define GAME_TITLE "Conway's Game Of Life"

#define PATH_SPLASH_BACKGROUND "../assets/res/SplashBackground.png"
#define SPLASHSTATE_DELAY_SECONDS 1.0f

#define BOARD_ROWS 50 
#define BOARD_COLUMNS 50
#define BOARD_MARGIN 50.0f

#define GENERATION_DELAY_SECONDS 1.0f

#define CELL_WIDTH (SCREEN_WIDTH-(2*BOARD_MARGIN))/BOARD_ROWS
#define CELL_HEIGHT (SCREEN_HEIGHT-(2*BOARD_MARGIN))/BOARD_COLUMNS
#define CELL_OUTLINE_THICKNESS 1.0f
#define CELL_ALIVE_FILL_COLOR sf::Color::Green
#define CELL_DEAD_FILL_COLOR sf::Color::White
#define CELL_OUTLINE_COLOR sf::Color::Black
