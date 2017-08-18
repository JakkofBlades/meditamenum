#include <algorithm>

#include "input.hpp"

InputController::InputController()
   : log_("Input"),
     pressed_keys()
{

}

int InputController::HandleKeyPress(sf::Event event)
{
   std::vector<sf::Keyboard::Key>::iterator it;

   it = std::find(pressed_keys.begin(), pressed_keys.end(), event.key.code);

   if (it == pressed_keys.end())
   {
      pressed_keys.push_back(event.key.code);
   }
}

int InputController::HandleKeyRelease(sf::Event event)
{
   std::vector<sf::Keyboard::Key>::iterator it;

   it = std::find(pressed_keys.begin(), pressed_keys.end(), event.key.code);

   if (it != pressed_keys.end())
   {
      pressed_keys.erase(it);
   }
}

int InputController::CheckInput()
{
   std::vector<sf::Keyboard::Key>::iterator it;

   int size = pressed_keys.size();

   if (!(size == 0))
   {
      log_.Warn() << "Num keys pressed : " << pressed_keys.size();
   }

   return size;
}

int InputController::PrintKeySequence()
{
   std::string seq;

   for (auto it : pressed_keys)
   {
      switch (it)
      {
      case sf::Keyboard::LControl:
      case sf::Keyboard::RControl:
         seq += "C-";
         break;
      case sf::Keyboard::W:
         seq += "W ";
         break;
      case sf::Keyboard::A:
         seq += "A ";
         break;
      case sf::Keyboard::S:
         seq += "S ";
         break;
      case sf::Keyboard::D:
         seq += "D ";
         break;
      }
   }

   if (!seq.empty())
   {
      log_.Warn() << seq;
   }
   return 1;
}
