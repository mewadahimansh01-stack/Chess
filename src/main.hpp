#include "Black_Clicked.hpp"
#include "Black_Normal.hpp"
#include "Chess_black_perspective_board.hpp"
#include "Chess_white_perspective_board.hpp"
#include "White_Clicked.hpp"
#include "White_Normal.hpp"
#include "logo.hpp"
#include "slider.hpp"
#include <SFML/Graphics.hpp>

// Change this when you want to change the window sizes and please don't chnage
// it in any of the functions'
constexpr unsigned int WINDOW_WIDTH{800};
constexpr unsigned int WINDOW_HEIGHT{600};
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

const sf::Texture sliderr(sf::Image({SLIDER_WIDTH, SLIDER_HEIGHT}, slider));

static const inline sf::Sprite setSliderLeft() {
  return sf::Sprite(sliderr, {{0, 0}, {64, 64}});
}

static const inline sf::Sprite setSliderRight() {
  return sf::Sprite(sliderr, {{0, 64}, {64, 64}});
}

static const inline sf::Sprite setWhiteClicked() {
  sf::Sprite WC(WhiteClicked);
  return WC;
}

static const inline sf::Sprite setBlackClicked() {
  sf::Sprite BC(blackClicked);
  return BC;
}

static const inline sf::Sprite setWhiteNormal() {
  sf::Sprite WN(whiteNormal);
  return WN;
}

static const inline sf::Sprite setBlackNormal() {
  sf::Sprite BN(blackNormal);
  return BN;
}

static const inline sf::RenderWindow setWindow() {
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

static const inline sf::Sprite setBoardBlack() {
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

static const inline sf::Sprite setBoardWhite() {
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
