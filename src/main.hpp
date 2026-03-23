#include "assets/BitcountPropDouble_Cursive-Light.hpp"
#include "assets/Black_Clicked.hpp"
#include "assets/Black_Normal.hpp"
#include "assets/Chess_black_perspective_board.hpp"
#include "assets/Chess_white_perspective_board.hpp"
#include "assets/White_Clicked.hpp"
#include "assets/White_Normal.hpp"
#include "assets/logo.hpp"
#include <SFML/Graphics.hpp>
enum class OPPONENT : char { AI, HUMAN };
enum class SIDE : char { BLACK, WHITE };
constexpr unsigned int WINDOW_WIDTH{800};
constexpr unsigned int WINDOW_HEIGHT{600};
constexpr sf::Color lightBeige(245, 222, 179, 255);
constexpr sf::Color mutedGreen(198, 221, 198, 255);
constexpr sf::Color gentleCream(255, 240, 220, 255);
const sf::Font defaultFont(BitcountPropDouble_Cursive_Light, 202460);
namespace answers {
static const inline sf::Text black() {
  sf::Text current(defaultFont, "Black", 30);
  current.setPosition({465, 330});
  current.setFillColor(sf::Color::Red);
  return current;
}
static const inline sf::Text white() {
  sf::Text current(defaultFont, "White", 30);
  current.setPosition({260, 330});
  current.setFillColor(sf::Color::Red);
  return current;
}
static const inline sf::Text ai() {
  sf::Text current(defaultFont, "AI", 30);
  current.setPosition({290, 330});
  current.setFillColor(sf::Color::Red);
  return current;
}
static const inline sf::Text human() {
  sf::Text current(defaultFont, "Human", 30);
  current.setPosition({455, 330});
  current.setFillColor(sf::Color::Red);
  return current;
}
} // namespace answers
namespace questions {
static const inline sf::Text stage1() {
  sf::Text current(defaultFont, "Whom do you want to play against?", 40);
  current.setPosition({40, 100});
  current.setFillColor(sf::Color::Red);
  return current;
}
static const inline sf::Text stage2() {
  sf::Text current(defaultFont, "Which color do you want to play as?", 40);
  current.setPosition({40, 100});
  current.setFillColor(sf::Color::Red);
  return current;
}
} // namespace questions
// TODO: There is some redundant data in the white buttons, please fix that
namespace clicked {
const sf::Texture blackClicked(
    sf::Image({BLACK_CLICKED_WIDTH, BLACK_CLICKED_HEIGHT}, Black_Clicked));
const sf::Texture WhiteClicked(
    sf::Image({WHITE_CLICKED_WIDTH, WHITE_CLICKED_WIDTH}, White_Clicked));
static const inline sf::Sprite white() {
  sf::Sprite WC(WhiteClicked, {{0, 0}, {48, 16}});
  WC.scale({2.0, 2.0});
  WC.setPosition({WINDOW_WIDTH / 2.0 - 148, WINDOW_HEIGHT / 2.0});
  return WC;
}
static const inline sf::Sprite black() {
  sf::Sprite BC(blackClicked);
  BC.scale({2.0, 2.0});
  BC.setPosition({WINDOW_WIDTH / 2.0 + 52, WINDOW_HEIGHT / 2.0});
  return BC;
}
} // namespace clicked
namespace normal {
const sf::Texture blackNormal(
    sf::Image({BLACK_NORMAL_WIDTH, BLACK_NORMAL_HEIGHT}, Black_Normal));
const sf::Texture whiteNormal(
    sf::Image({WHITE_NORMAL_WIDTH, WHITE_NORMAL_HEIGHT}, White_Normal));
static const inline sf::Sprite white() {
  sf::Sprite WN(whiteNormal, {{0, 0}, {48, 16}});
  WN.setPosition({WINDOW_WIDTH / 2.0 - 148, WINDOW_HEIGHT / 2.0});
  WN.scale({2.0, 2.0});
  return WN;
}
static const inline sf::Sprite black() {
  sf::Sprite BN(blackNormal);
  BN.scale({2.0, 2.0});
  BN.setPosition({WINDOW_WIDTH / 2.0 + 52, WINDOW_HEIGHT / 2.0});
  return BN;
}
} // namespace normal
namespace window {
static const inline sf::RenderWindow set() {
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
  window.setFramerateLimit(60);
  return window;
}
} // namespace window
namespace board {
const sf::Texture blackBoardTexture(sf::Image(
    {CHESS_BLACK_PERSPECTIVE_BOARD_WIDTH, CHESS_BLACK_PERSPECTIVE_BOARD_HEIGHT},
    Chess_black_perspective_board));
const sf::Texture whiteBoardTexture(sf::Image(
    {CHESS_WHITE_PERSPECTIVE_BOARD_WIDTH, CHESS_WHITE_PERSPECTIVE_BOARD_HEIGHT},
    Chess_white_perspective_board));
static const inline sf::Sprite black() {
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
