/*
 Some of the values related to images have been hard coded, so if you change any
 of the images and any bugs appear please check here first.
 */

#include "assets/Black_Clicked.hpp"
#include "assets/Black_Normal.hpp"
#include "assets/Chess_black_perspective_board.hpp"
#include "assets/Chess_white_perspective_board.hpp"
#include "assets/White_Clicked.hpp"
#include "assets/White_Normal.hpp"
#include "assets/logo.hpp"
#include <SFML/Graphics.hpp>

enum class OPPONENT: char {AI, HUMAN};
enum class SIDE: char {BLACK, WHITE};

// Change this when you want to change the window sizes and please don't chnage
// it in any of the functions'
constexpr unsigned int WINDOW_WIDTH{800};
constexpr unsigned int WINDOW_HEIGHT{600};

constexpr sf::Color lightBeige(245, 222, 179, 255);
constexpr sf::Color mutedGreen(198, 221, 198, 255);
constexpr sf::Color gentleCream(255, 240, 220, 255);

const sf::Texture blackBoardTexture(sf::Image(
    {CHESS_BLACK_PERSPECTIVE_BOARD_WIDTH, CHESS_BLACK_PERSPECTIVE_BOARD_HEIGHT},
    Chess_black_perspective_board));
const sf::Texture whiteBoardTexture(sf::Image(
    {CHESS_WHITE_PERSPECTIVE_BOARD_WIDTH, CHESS_WHITE_PERSPECTIVE_BOARD_HEIGHT},
    Chess_white_perspective_board));

const sf::Texture blackClicked(
    sf::Image({BLACK_CLICKED_WIDTH, BLACK_CLICKED_HEIGHT}, Black_Clicked));
const sf::Texture WhiteClicked(
    sf::Image({WHITE_CLICKED_WIDTH, WHITE_CLICKED_WIDTH}, White_Clicked));
const sf::Texture blackNormal(
    sf::Image({BLACK_NORMAL_WIDTH, BLACK_NORMAL_HEIGHT}, Black_Normal));
const sf::Texture whiteNormal(
    sf::Image({WHITE_NORMAL_WIDTH, WHITE_NORMAL_HEIGHT}, White_Normal));

namespace clicked {
static const inline sf::Sprite white() {
  sf::Sprite WC(WhiteClicked);
  return WC;
}

static const inline sf::Sprite black() {
  sf::Sprite BC(blackClicked);
  return BC;
}
} // namespace clicked

namespace normal {
static const inline sf::Sprite white() {
  sf::Sprite WN(whiteNormal);
  return WN;
}

static const inline sf::Sprite black() {
  sf::Sprite BN(blackNormal);
  return BN;
}
} // namespace normal

static const inline sf::RenderWindow setWindow() {
  // Changing the window dimensions here might screw up the presentation on
  // screen
  sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Chess",
                          sf::Style::Close);
  const sf::VideoMode desktopMode{sf::VideoMode::getDesktopMode()};
  const int centerX{
      static_cast<int>(desktopMode.size.x / 2 - WINDOW_WIDTH / 2)};
  const int centerY{
      static_cast<int>(desktopMode.size.y / 2 - WINDOW_HEIGHT / 2)};
  window.setPosition({centerX, centerY});
  const sf::Image icon({LOGO_WIDTH, LOGO_HEIGHT}, logo);
  window.setIcon(icon);
  return window;
}

namespace board {
static const inline sf::Sprite black() {
  // Considering that the sprites were not scaled from their texture
  // counterparts and are of the same size
  const sf::Vector2f boardPosition{
      static_cast<float>(WINDOW_WIDTH / 2.0 -
                         blackBoardTexture.getSize().x / 2.0),
      static_cast<float>(WINDOW_HEIGHT / 2.0 -
                         blackBoardTexture.getSize().y / 2.0)};
  sf::Sprite blackBoard(blackBoardTexture);
  blackBoard.setPosition(boardPosition);
  return blackBoard;
}

static const inline sf::Sprite white() {
  // Considering that the sprites were not scaled from their texture
  // counterparts and are of the same size
  const sf::Vector2f boardPosition{
      static_cast<float>(WINDOW_WIDTH / 2.0 -
                         blackBoardTexture.getSize().x / 2.0),
      static_cast<float>(WINDOW_HEIGHT / 2.0 -
                         blackBoardTexture.getSize().y / 2.0)};
  sf::Sprite whiteBoard(whiteBoardTexture);
  whiteBoard.setPosition(boardPosition);
  return whiteBoard;
}
} // namespace board
