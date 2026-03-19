#include "main.hpp"
#include <SFML/System/Vector2.hpp>

int main() {
  sf::RenderWindow window = setWindow();

  sf::Sprite blackBoard = setBoardBlack();
  sf::Sprite whiteBoard = setBoardWhite();

  while (window.isOpen()) {
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
    }

    window.clear(sf::Color::Cyan);

    window.draw(blackBoard);

    window.display();
  }
}
