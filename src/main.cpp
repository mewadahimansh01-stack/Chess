#include "main.hpp"

int main() {
  sf::RenderWindow window {setWindow()};

  // Board
  sf::Sprite blackBoard {board::black()};
  sf::Sprite whiteBoard {board::white()};

  // Button
  sf::Sprite whiteClicked{clicked::white()};
  sf::Sprite whiteNormal{normal::white()};
  sf::Sprite blackClicked{clicked::black()};
  sf::Sprite blackNormal{normal::black()};

  auto opponent {OPPONENT::AI};
  auto side {SIDE::WHITE};

  while (window.isOpen()) {
    while (const std::optional event { window.pollEvent()}) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
    }

    window.clear(mutedGreen);

    window.display();
  }
}
