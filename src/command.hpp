#ifndef _COMMAND_H_
#define _COMMAND_H_

#include "logger.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

class Command
{
public:
   virtual ~Command() {}
   virtual void Execute() = 0;
   virtual void Undo() = 0;

   bool isRepeated();
   void isRepeated(bool is_repeated);

protected:
   bool is_repeated_ = false;

private:
};


// Null Command
class NullCommand : public Command
{
public:
   NullCommand();
   virtual void Execute();
   virtual void Undo();

private:
   dahl::iris::Logger log_;
};


// Print command
class PrintCommand : public Command
{
public:
   PrintCommand(std::string log_name);

   virtual void Execute();
   virtual void Undo();

private:
   dahl::iris::Logger log_;
};

// Move command
class MoveCommand : public Command
{
public:
   MoveCommand(sf::Sprite* entity, sf::Vector2f magnitude);

   virtual void Execute();
   virtual void Undo();

private:
   sf::Sprite* entity_;
   sf::Vector2f magnitude_;

   dahl::iris::Logger log_;
};

#endif
