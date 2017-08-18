/*******************************************************************************
 * File: logger.cpp
 * Author: Samuel Dahlberg
 * Desc: Encapsulates file and console logging capability
 ******************************************************************************/

#include "logger.hpp"

#include <iostream>
#include <ctime>

// #include <boost/date_time/posix_time/posix_time.hpp>

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace dahl {
namespace iris {


/*******************************************************************************
 * Contructors
 ******************************************************************************/
Logger::Logger(const std::string& name)
    : name_(name) {}


/*******************************************************************************
 * Public Methods
 ******************************************************************************/
// Info
void Logger::Info(const std::string& msg)
{
   std::cout << "INFO[" << name_ << "]: " << msg << std::endl;
}

LogBuilder Logger::Info(void)
{
   LogStream::Ptr log_stream(new LogStream(name_, LogLevel::INFO));
   return LogBuilder(name_, log_stream);
}

// Warn
void Logger::Warn(const std::string& msg)
{
   std::cout << "WARN[" << name_ << "]: " << msg << std::endl;
}

LogBuilder Logger::Warn(void)
{
   LogStream::Ptr log_stream(new LogStream(name_, LogLevel::WARN));
   return LogBuilder(name_, log_stream);
}

// Error
void Logger::Error(const std::string& msg)
{
   std::cout << "ERROR[" << name_ << "]: " << msg << std::endl;
}

LogBuilder Logger::Error(void)
{
   LogStream::Ptr log_stream(new LogStream(name_, LogLevel::ERR));
   return LogBuilder(name_, log_stream);
}

// Debug
void Logger::Debug(const std::string& msg)
{
   std::cout << "DEBUG[" << name_ << "]: " << msg << std::endl;
}

LogBuilder Logger::Debug(void)
{
   LogStream::Ptr log_stream(new LogStream(name_, LogLevel::DEBUG));
   return LogBuilder(name_, log_stream);
}

/*******************************************************************************
 * Log Stream
 ******************************************************************************/
LogStream::LogStream()
   : stream_() {}

LogStream::LogStream(const std::string& name, LogLevel level)
   : stream_(),
     name_(name),
     log_level_(level) {}


LogStream::~LogStream() {
   std::cout << GetTimestamp() << " " << GetLogLevelString(log_level_) << "["
             << name_<< "]: " << stream_.str() << std::endl;
}

std::string LogStream::GetTimestamp() {
   time_t    now = time(0);
   struct tm tstruct = *localtime(&now);
   char      buffer[32];

   strftime(buffer, sizeof(buffer), "%Y-%m-%d %X", &tstruct);

   return buffer;
}

std::string LogStream::GetLogLevelString(LogLevel level)
{
   std::string ret;

   switch(level) {
      case INFO:
         ret = "INFO";
         break;
      case WARN:
         ret = "WARN";
         break;
      case ERR:
         ret = "ERROR";
         break;
      case DEBUG:
         ret = "DEBUG";
         break;
      default:
         ret = "UNKNOWN";
   }

   return ret;
}

}
}
