
#include "LogServiceImpl.h"
#include "LogEntry.h"

#include <future>

namespace us { namespace logservice {

LogServiceImpl::LogServiceImpl(std::shared_ptr<LogReaderServiceImpl> reader) : _log(reader)
{

}

void LogServiceImpl::Log(SeverityLevel level, const std::string& message)
{
  SendLogEvent(LogEntry(nullptr, nullptr, level, message, ServiceReferenceU(), 0));
}

void LogServiceImpl::Log(SeverityLevel level, const std::string& message, std::exception_ptr ex)
{
  SendLogEvent(LogEntry(nullptr, ex, level, message, ServiceReferenceU(), 0));
}

void LogServiceImpl::Log(ServiceReferenceU sr, SeverityLevel level, const std::string& message)
{
  SendLogEvent(LogEntry(nullptr, nullptr, level, message, sr, 0));
}

void LogServiceImpl::Log(ServiceReferenceU sr, SeverityLevel level, const std::string& message, std::exception_ptr ex)
{
  SendLogEvent(LogEntry(nullptr, ex, level, message, sr, 0));
}

void LogServiceImpl::SendLogEvent(LogEntry&& entry)
{
  // this is actually a synchronous call since the return std::future
  // isn't moved from or bound to a reference.
  auto f = std::async(std::launch::async, [this, &entry]
                    {
                      _log->Logged(std::forward<LogEntry>(entry));
                    });
}

} // namespace logservice

} // namespace us
