#include "main.hpp"
int main() {
  sf::RenderWindow window{window::set()};
  const sf::Sprite blackBoard{board::black()};
  const sf::Sprite whiteBoard{board::white()};
  const sf::Sprite whiteClicked{clicked::white()};
  const sf::Sprite whiteNormal{normal::white()};
  const sf::Sprite blackClicked{clicked::black()};
  const sf::Sprite blackNormal{normal::black()};
  enum OPPONENT opponent { OPPONENT::AI };
  enum SIDE side { SIDE::WHITE };
  char stage{1};
  const sf::Text black = answers::black();
  const sf::Text white = answers::white();
  const sf::Text current = questions::stage1();
  const sf::Text ai = answers::ai();
  const sf::Text human = answers::human();
  const sf::Text ncurrent = questions::stage2();
  while (window.isOpen()) {
    sf::Vector2f mousePos{
        static_cast<sf::Vector2f>(sf::Mouse::getPosition(window))};
    bool check{sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)};
    sf::FloatRect whiteBounds{whiteClicked.getGlobalBounds()};
    sf::FloatRect blackBounds{blackClicked.getGlobalBounds()};
    while (const std::optional event{window.pollEvent()}) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
      if (const auto *mouseEvent{
              event->getIf<sf::Event::MouseButtonPressed>()}) {
        if (stage == 1) {
          if ((whiteBounds.contains(mousePos)) && check) {
            opponent = OPPONENT::AI;
            stage = 2;
          } else if ((blackBounds.contains(mousePos)) && check) {
            opponent = OPPONENT::HUMAN;
            stage = 2;
          }
        } else if (stage == 2) {
          if ((whiteBounds.contains(mousePos)) && check) {
            side = SIDE::WHITE;
            stage = 3;
          } else if ((blackBounds.contains(mousePos)) && check) {
            side = SIDE::BLACK;
            stage = 3;
          }
        }
      }
    }
    window.clear(mutedGreen);
    if (stage == 1) {
      window.draw(current);
      window.draw(ai);
      window.draw(human);
      if (whiteBounds.contains(mousePos)) {
        window.draw(whiteClicked);
      } else {
        window.draw(whiteNormal);
      }
      if (blackBounds.contains(mousePos)) {
        window.draw(blackClicked);
      } else {
        window.draw(blackNormal);
      }
    } else if (stage == 2) {
      window.draw(ncurrent);
      window.draw(black);
      window.draw(white);
      if (whiteBounds.contains(mousePos)) {
        window.draw(whiteClicked);
      } else {
        window.draw(whiteNormal);
      }
      if (blackBounds.contains(mousePos)) {
        window.draw(blackClicked);
      } else {
        window.draw(blackNormal);
      }
    } else {
    }
    window.display();
  }
}
