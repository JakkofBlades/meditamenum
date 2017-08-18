#pragma once

#include <vector>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "logger.hpp"

class InputController
{
public:
   InputController();
   int HandleKeyPress(sf::Event event);
   int HandleKeyRelease(sf::Event event);
   int CheckInput();
   int PrintKeySequence();

private:

   dahl::iris::Logger log_;
   std::vector<sf::Keyboard::Key> pressed_keys;
};
