//******************************************************************************
// File: utility.h
// Author: Samuel Dahlberg
//******************************************************************************

#ifndef _UTILITY_H_
#define _UTILITY_H_

#define STRINGIZE(x) "#x"

#include <string>

#include "logger.hpp"

class Utility
{
   Stringize(std::string string)
   {
      logger.Info(STRINGIZE(string));
   }
}

#endif
