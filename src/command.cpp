#include "command.hpp"

bool Command::isRepeated() { return is_repeated_; }
void Command::isRepeated(bool is_repeated) {is_repeated_ = is_repeated;};

PrintCommand::PrintCommand(std::string log_name)
   : log_(log_name)
{
   this->isRepeated(true);
}

void PrintCommand::Execute()
{
   log_.Info() << "Print Command";
}

// No-op
void PrintCommand::Undo() {}



NullCommand::NullCommand()
   : log_("Null") {}

void NullCommand::Execute()
{
   log_.Info() << "Null Command";
}

// No-op
void NullCommand::Undo() {}


MoveCommand::MoveCommand(sf::Sprite *entity, sf::Vector2f magnitude)
   : log_("Move"),
     entity_(entity),
     magnitude_(magnitude)
{
   this->isRepeated(true);
}

void MoveCommand::Execute(void)
{
   if(magnitude_.x < 0 &&
      entity_->getPosition().x <= 0)
   {
      // Do nothing
      return;
   }

   if(magnitude_.x > 0 &&
      entity_->getPosition().x >= 800)
   {
      // Do nothing
      return;
   }

   entity_->move(magnitude_);
}

void MoveCommand::Undo(void)
{
   entity_->move(-magnitude_);
}
