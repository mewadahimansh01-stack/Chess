#pragma once
#include "../assets/board_black.h"
#include "../assets/board_white.h"
#include <SFML/Graphics.hpp>


static const sf::Texture board_from_black_perspective(sf::Image({BOARD_BLACK_WIDTH, BOARD_BLACK_HEIGHT}, board_black));
static const sf::Texture board_from_white_perspective(sf::Image({BOARD_WHITE_WIDTH, BOARD_WHITE_HEIGHT}, board_white));

static const inline sf::Sprite load_black_perspective_board() {
    return sf::Sprite(board_from_black_perspective);
}

static const inline sf::Sprite load_white_perspective_board() {
    return sf::Sprite(board_from_white_perspective);
}
