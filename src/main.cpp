#include "headers/window.hpp"
#include "headers/board.hpp"
#include <SFML/Graphics.hpp>


int main() {
  sf::RenderWindow window{load_preset_window()};
  sf::Sprite board_from_black_perspective{load_black_perspective_board()};
  sf::Sprite board_from_white_perspective{load_white_perspective_board()};

  while (window.isOpen()) {
    while (std::optional event{window.pollEvent()}) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
    }

    window.clear(sf::Color::Yellow);

    window.display();
  }
}
