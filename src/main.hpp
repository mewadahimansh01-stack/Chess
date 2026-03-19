#include "Chess_black_perspective_board.hpp"
#include "Chess_white_perspective_board.hpp"
#include "logo.hpp"
#include <SFML/Graphics.hpp>

constexpr unsigned int WINDOW_WIDTH{800};
constexpr unsigned int WINDOW_HEIGHT{600};

const sf::Texture blackBoardTexture(sf::Image(
    {CHESS_BLACK_PERSPECTIVE_BOARD_WIDTH, CHESS_BLACK_PERSPECTIVE_BOARD_HEIGHT},
    Chess_black_perspective_board));
const sf::Texture whiteBoardTexture(sf::Image(
    {CHESS_WHITE_PERSPECTIVE_BOARD_WIDTH, CHESS_WHITE_PERSPECTIVE_BOARD_HEIGHT},
    Chess_white_perspective_board));

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
