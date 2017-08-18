/*******************************************************************************
 * File: logger.hpp
 *
 * Author: Samuel Dahlberg
 *
 * Desc: Logging system using C++ streams with different severity levels.  The
 *       stream will log to standard output, files and networks streams at the
 *       users discretion
 ******************************************************************************/


/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <sstream>
#include <memory>

/*******************************************************************************
 * Namespace
 ******************************************************************************/
namespace dahl {
namespace iris {


/*******************************************************************************
 * Enums
 ******************************************************************************/
enum LogLevel {
   INFO = 1,
   WARN = 2,
   ERR = 3,
   DEBUG = 4
};


/*******************************************************************************
 * Class : LogStream
 ******************************************************************************/
class LogStream
{
public:
   typedef std::shared_ptr<LogStream> Ptr;

   LogStream();
   LogStream(const std::string& name, LogLevel level);

   ~LogStream();

   // @NOTE dahlbergs: May not need this. Currently unused.
   std::ostream& stream() { return stream_; }

private:
   std::string GetTimestamp(void);
   std::string GetLogLevelString(LogLevel level);

   std::string name_;
   std::ostringstream stream_;

   LogLevel log_level_;
};


/*******************************************************************************
 * Class : LogBuilder
 ******************************************************************************/
class LogBuilder
{
public:
   LogBuilder() {}

   LogBuilder(const std::string& name, LogStream::Ptr stream_holder)
      : name_(name),
        stream_holder_(stream_holder) {}

   LogBuilder(const std::string& name)
      : name_(name) {}

   template<class T>
   LogBuilder& operator<<(const T &data) {
      stream_holder_->stream() << data;
      return *this;
   }

private:
   LogStream::Ptr stream_holder_;
   std::string name_;
};

/*******************************************************************************
 * Class : Logger
 ******************************************************************************/

class Logger
{
public:
   Logger(const std::string& name);

   void Info(const std::string& msg);
   LogBuilder Info(void);

   void Warn(const std::string& msg);
   LogBuilder Warn(void);

   void Error(const std::string& msg);
   LogBuilder Error(void);

   void Debug(const std::string& msg);
   LogBuilder Debug(void);

private:
   std::string name_;
};

} // end namespace iris
} // end namespace dahl
