#include "main.hpp"

int main() {
  sf::RenderWindow window {setWindow()};

  // Board
  sf::Sprite blackBoard {setBoardBlack()};
  sf::Sprite whiteBoard {setBoardWhite()};

  // Button
  sf::Sprite whiteClicked{setWhiteClicked()};
  sf::Sprite whiteNormal{setWhiteNormal()};
  sf::Sprite blackClicked{setBlackClicked()};
  sf::Sprite blackNormal{setBlackNormal()};

  while (window.isOpen()) {
    while (const std::optional event { window.pollEvent()}) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
    }

    window.clear(sf::Color::Cyan);

    window.display();
  }
}
