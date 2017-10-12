//******************************************************************************
// File: utility.cpp
// Author: Samuel Dahlberg
//******************************************************************************

#include "utility.hpp"

Utility::Utility()
   : log_("Utility")
{

}

Utility::Stringize(std::string string)
{
   log_.Info(STRINGIZE(string));
}
