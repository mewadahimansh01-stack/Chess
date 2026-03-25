#pragma once
#include "../assets/logo.h"
#include <SFML/Graphics.hpp>

enum class state : char { menu, play, restart };

static constexpr unsigned window_width{800};
static constexpr unsigned window_height{600};
static constexpr char window_title[]{"Chess"};
static const sf::Image window_icon{sf::Image({LOGO_WIDTH, LOGO_HEIGHT}, logo)};

static const inline sf::RenderWindow load_preset_window() {
  sf::RenderWindow window(sf::VideoMode({window_width, window_height}),
                          window_title, sf::Style::Close);
  sf::VideoMode screen{sf::VideoMode::getDesktopMode()};
  window.setPosition(
      {static_cast<int>(screen.size.x / 2.0 - window_width / 2.0),
       static_cast<int>(screen.size.y / 2.0 - window_height / 2.0)});
  window.setIcon(window_icon);
  return window;
}
