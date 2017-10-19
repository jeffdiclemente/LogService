#ifndef LOG_SERVICE_IMPL_H__
#define LOG_SERVICE_IMPL_H__

#include "LogEntry.h"
#include "LogService.h"
#include "LogReaderServiceImpl.h"
#include "cppmicroservices/ServiceReference.h"

#include <exception>
#include <memory>
#include <string>

namespace cppmicroservices { namespace logservice {

class LogServiceImpl : public LogService
{
public:
  LogServiceImpl(std::shared_ptr<LogReaderServiceImpl> reader);
  virtual ~LogServiceImpl() {}

  void Log(SeverityLevel level, const std::string& message);
  void Log(SeverityLevel level, const std::string& message, std::exception_ptr ex);
  void Log(ServiceReferenceU sr, SeverityLevel level, const std::string& message);
  void Log(ServiceReferenceU sr, SeverityLevel level, const std::string& message, std::exception_ptr ex);

private:
  void SendLogEvent(LogEntry&& entry);

  std::shared_ptr<LogReaderServiceImpl> _log;
};

} // namespace logservice

} // namespace cppmicroservices

#endif // LOG_SERVICE_IMPL_H__
