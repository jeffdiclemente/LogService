
#include "LogEntry.h"
#include "LogEntryPrivate.h"

namespace cppmicroservices { namespace logservice {

LogEntry::LogEntry(Bundle* bundle,
                    const std::exception_ptr ex,
                    const SeverityLevel& level,
                    const std::string& message,
                    const ServiceReferenceU& sr,
                    long t) : d(new LogEntryPrivate(bundle, ex, level, message, sr, t))
{

}

LogEntry::LogEntry(const LogEntry&)
{

}

LogEntry::~LogEntry() {}

std::shared_ptr<Bundle> LogEntry::GetBundle() const
{
  return d->_bundle;
}

std::exception_ptr LogEntry::GetException() const
{
  return d->_ex;
}

SeverityLevel LogEntry::GetLevel() const
{
  return d->_level;
}

std::string LogEntry::GetMessage() const
{
  return d->_message;
}

ServiceReferenceU LogEntry::GetServiceReference() const
{
  return d->_sr;
}

long LogEntry::GetTime() const
{
  return d->_time;
}

bool operator==(const LogEntry& rhs, const LogEntry& lhs)
{
  return (rhs.GetBundle() == lhs.GetBundle() &&
          rhs.GetException() == lhs.GetException() &&
          rhs.GetLevel() == lhs.GetLevel() &&
          rhs.GetMessage() == lhs.GetMessage() &&
          rhs.GetTime() == lhs.GetTime());
}

std::ostream& operator<<(std::ostream& os, const SeverityLevel l)
{
  switch(l)
  {
    case SeverityLevel::LOG_ERROR:    return os << "ERROR";
    case SeverityLevel::LOG_WARNING:  return os << "WARNING";
    case SeverityLevel::LOG_INFO:     return os << "INFO";
    case SeverityLevel::LOG_DEBUG:    return os << "DEBUG";
    default:                          return os << "UNKNOWN (" << static_cast<unsigned int>(l) << ")";
  }
}

std::ostream& operator<<(std::ostream& os, const std::exception_ptr ex)
{
  if(!ex) return os << "NONE";
  try
  {
    std::rethrow_exception(ex);
  }
  catch(const std::exception& e)
  {
    os << e.what();
  }
  catch(...)
  {
    os << "unknown exception";
  }
  return os;
}

std::ostream& operator<<(std::ostream& os, const LogEntry& le)
{
  os << "Bundle: " << le.GetBundle()
      << "\n Service Reference: " << le.GetServiceReference()
      << "\n Message: " << le.GetMessage()
      << "\n Severity Level: " << le.GetLevel()
      << "\n Exception: " << le.GetException()
      << "\n Time: " << le.GetTime();
  return os;
}

} // namespace logservice

} // namespace cppmicroservices
