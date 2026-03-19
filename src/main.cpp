#include "main.hpp"

int main() {
  sf::RenderWindow window {setWindow()};

  // Boards Group
  sf::Sprite blackBoard {setBoardBlack()};
  sf::Sprite whiteBoard {setBoardWhite()};

  // Buttons Group
  sf::Sprite whiteClicked{setWhiteClicked()};
  sf::Sprite whiteNormal{setWhiteNormal()};
  sf::Sprite blackClicked{setBlackClicked()};
  sf::Sprite blackNormal{setBlackNormal()};

  // Slider
  sf::Sprite sliderLeft{setSliderLeft()};
  sf::Sprite sliderRight{setSliderRight()};

  while (window.isOpen()) {
    while (const std::optional event { window.pollEvent()}) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
    }

    window.clear(sf::Color::Cyan);

    window.draw(blackBoard);

    window.display();
  }
}
