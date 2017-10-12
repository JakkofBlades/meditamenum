//******************************************************************************
// File: config.h
// Author: Samuel Dahlberg
//******************************************************************************

#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <string>

class Config
{
   Config();
   ~Config();

   LoadConfig(std::string filePath);
}

#endif
