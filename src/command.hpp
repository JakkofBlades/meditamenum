#ifndef _COMMAND_H_
#define _COMMAND_H_

#include "logger.hpp"

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

class NullCommand : public Command
{
public:
   NullCommand();
   virtual void Execute();
   virtual void Undo();

private:
   dahl::iris::Logger log_;
};


class PrintCommand : public Command
{
public:
   PrintCommand(std::string log_name);

   virtual void Execute();
   virtual void Undo();

private:
   dahl::iris::Logger log_;
};

#endif
