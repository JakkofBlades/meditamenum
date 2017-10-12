#include <unordered_map>

#include "input.hpp"

//******************************************************************************
// Constructors and Destructors
//******************************************************************************
InputController::InputController()
   : log_("Input"),
     current_command_("") {}

//******************************************************************************
// Public Function Definitions
//******************************************************************************
int InputController::HandleKeyPress(sf::Event event)
{
   std::string command;
   std::string key = GetStringFromKeyCode(event.key.code);

   if(!key.empty())
   {
      command += GetModifier() + key;

      auto cmd = global_key_map.find(command);

      if(cmd != global_key_map.end())
      {
         if (cmd->second->isRepeated())
         {
            cmd->second->Execute();
            // log_.Warn() << command;
         }
      }
   }
   return 0;
}

int InputController::HandleKeyRelease(sf::Event event)
{
   std::string command = current_command_;
   std::string key = GetStringFromKeyCode(event.key.code);

   if(!key.empty())
   {
      command += (GetModifier() + key);

      auto pref = prefix_key_map.find(command);

      if(pref != prefix_key_map.end())
      {
         log_.Warn() << "Prefix found";
         current_command_ = command + " ";
      } else {
         auto cmd = global_key_map.find(command);

         if(cmd != global_key_map.end())
         {
            // log_.Warn() << command;

            if(!cmd->second->isRepeated())
            {
               cmd->second->Execute();
            }
         }
         current_command_ = "";
      }
   }
   return 0;
}

void InputController::AddKeyCommand(std::string key_seq, Command* cmd)
{
   global_key_map.insert(std::make_pair(key_seq, cmd));
}

void InputController::AddKeyPrefix(std::string key_seq)
{
   prefix_key_map.insert(std::make_pair(key_seq, key_seq));
}

std::string InputController::GetModifier()
{
   std::string modifier;

   if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) ||
      sf::Keyboard::isKeyPressed(sf::Keyboard::RControl))
   {
      modifier += "C-";
   }

   if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) ||
      sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
   {
      modifier += "S-";
   }

   if(sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) ||
      sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt))
   {
      modifier += "M-";
   }

   return modifier;
}

std::string InputController::GetStringFromKeyCode(sf::Keyboard::Key key)
{
   std::string keyString = "";

   // TODO dahlbergs: Consider making this into a map.
   switch(key)
   {
   case sf::Keyboard::A:    {keyString = "a"; break;}
   case sf::Keyboard::B:    {keyString = "b"; break;}
   case sf::Keyboard::C:    {keyString = "c"; break;}
   case sf::Keyboard::D:    {keyString = "d"; break;}
   case sf::Keyboard::E:    {keyString = "e"; break;}
   case sf::Keyboard::F:    {keyString = "f"; break;}
   case sf::Keyboard::G:    {keyString = "g"; break;}
   case sf::Keyboard::H:    {keyString = "h"; break;}
   case sf::Keyboard::I:    {keyString = "i"; break;}
   case sf::Keyboard::J:    {keyString = "j"; break;}
   case sf::Keyboard::K:    {keyString = "k"; break;}
   case sf::Keyboard::L:    {keyString = "l"; break;}
   case sf::Keyboard::M:    {keyString = "m"; break;}
   case sf::Keyboard::N:    {keyString = "n"; break;}
   case sf::Keyboard::O:    {keyString = "o"; break;}
   case sf::Keyboard::P:    {keyString = "p"; break;}
   case sf::Keyboard::Q:    {keyString = "q"; break;}
   case sf::Keyboard::R:    {keyString = "r"; break;}
   case sf::Keyboard::S:    {keyString = "s"; break;}
   case sf::Keyboard::T:    {keyString = "t"; break;}
   case sf::Keyboard::U:    {keyString = "u"; break;}
   case sf::Keyboard::V:    {keyString = "v"; break;}
   case sf::Keyboard::W:    {keyString = "w"; break;}
   case sf::Keyboard::X:    {keyString = "x"; break;}
   case sf::Keyboard::Y:    {keyString = "y"; break;}
   case sf::Keyboard::Z:    {keyString = "z"; break;}
   case sf::Keyboard::Num0: {keyString = "0"; break;}
   case sf::Keyboard::Num1: {keyString = "1"; break;}
   case sf::Keyboard::Num2: {keyString = "2"; break;}
   case sf::Keyboard::Num3: {keyString = "3"; break;}
   case sf::Keyboard::Num4: {keyString = "4"; break;}
   case sf::Keyboard::Num5: {keyString = "5"; break;}
   case sf::Keyboard::Num6: {keyString = "6"; break;}
   case sf::Keyboard::Num7: {keyString = "7"; break;}
   case sf::Keyboard::Num8: {keyString = "8"; break;}
   case sf::Keyboard::Num9: {keyString = "9"; break;}
   default:  keyString = "";
   }

   return keyString;
}
