#pragma once

#include <vector>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include <unordered_map>

#include "logger.hpp"
#include "command.hpp"

class InputController
{
public:
   InputController();
   int HandleKeyPress(sf::Event event);
   int HandleSequentialKeyPress(sf::Event event);
   int HandleKeyRelease(sf::Event event);
   int CheckInput();
   int ProcessInput();
   int PrintKeySequence();

   void AddKeyCommand(std::string key_seq, Command* cmd);
   void AddKeyPrefix(std::string key_seq);

private:
   std::string GetModifier();
   std::string GetStringFromKeyCode(sf::Keyboard::Key key);

   dahl::iris::Logger log_;
   std::vector<sf::Keyboard::Key> pressed_keys;
   std::vector<sf::Keyboard::Key> input_key_queue;
   std::unordered_map<std::string, Command*> global_key_map;
   std::unordered_map<std::string, std::string> prefix_key_map;

   std::string current_command_;

   std::string commandBuilder;
};
