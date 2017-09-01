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

