
#ifndef LOG_ENTRY_H__
#define LOG_ENTRY_H__

#include "usILogServiceExport.h"

#include "cppmicroservices/Bundle.h"
#include "cppmicroservices/ServiceReference.h"
#include "LogService.h"

#include <exception>
#include <memory>
#include <ostream>
#include <string>

namespace cppmicroservices { namespace logservice {

class LogEntryPrivate;

class US_LogService_EXPORT LogEntry
{
public:
  LogEntry(Bundle bundle,
            const std::exception_ptr ex,
            const SeverityLevel& level,
            const std::string& message,
            const ServiceReferenceU& sr,
            long t);
  virtual ~LogEntry();
  LogEntry(const LogEntry&);
  LogEntry& operator=(const LogEntry&) = delete;

  virtual Bundle GetBundle() const;
  virtual std::exception_ptr GetException() const;
  virtual SeverityLevel GetLevel() const;
  virtual std::string GetMessage() const;
  virtual ServiceReferenceU GetServiceReference() const;
  virtual long GetTime() const;

private:
  std::unique_ptr<LogEntryPrivate> d;
};

US_LogService_EXPORT bool operator==(const LogEntry&, const LogEntry&);
US_LogService_EXPORT std::ostream& operator<<(std::ostream& os, const SeverityLevel);
US_LogService_EXPORT std::ostream& operator<<(std::ostream& os, const std::exception_ptr);
US_LogService_EXPORT std::ostream& operator<<(std::ostream& os, const LogEntry&);


} // namespace logservice

} // namespace cppmicroservices

#endif // LOG_ENTRY_H__
