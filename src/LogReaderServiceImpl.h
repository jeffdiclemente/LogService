#ifndef LOG_READER_SERVICE_IMPL_H__
#define LOG_READER_SERVICE_IMPL_H__


#include "LogReaderService.h"
#include "LogEntry.h"
#include "LogEntryStore.h"

#include <memory>
#include <mutex>
#include <forward_list>

namespace cppmicroservices { namespace logservice {

class LogReaderServiceImpl : public LogReaderService
{
public:
  LogReaderServiceImpl(std::shared_ptr<LogEntryStore> store);
  virtual ~LogReaderServiceImpl() {}

  void AddLogListener(LogListener listener);
  std::vector<LogEntry> GetLog();
  void RemoveLogListener(LogListener listener);

  void Logged(const LogEntry& entry);

private:
  std::mutex _listener_lock;
  std::forward_list<LogListener> _log_listeners;
  std::shared_ptr<LogEntryStore> _log;
};

} // namespace logservice

} // namespace cppmicroservices

#endif // LOG_READER_SERVICE_IMPL_H__
