#ifndef LOG_ENTRY_IMPL_H__
#define LOG_ENTRY_IMPL_H__

#include "LogEntry.h"

namespace cppmicroservices { namespace logservice {

class LogEntryPrivate
{
public:
  LogEntryPrivate(Bundle bundle,
              const std::exception_ptr ex,
              const SeverityLevel& level,
              const std::string& message,
              const ServiceReferenceU& sr,
              long t);
  virtual ~LogEntryPrivate() = default;
  LogEntryPrivate(const LogEntry&) = delete;
  LogEntryPrivate& operator=(const LogEntry&) = delete;

private:
  std::shared_ptr<Bundle> _bundle;
  ServiceReferenceU _sr;
  std::string _message;
  std::exception_ptr _ex;
  SeverityLevel _level;
  long _time;

  friend class LogEntry;
};

} // namespace logservice

} // namespace cppmicroservices

#endif // LOG_ENTRY_IMPL_H__
