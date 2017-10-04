
#include "LogReaderService.h"
#include "LogReaderServiceImpl.h"

namespace us { namespace logservice {

LogReaderServiceImpl::LogReaderServiceImpl(std::shared_ptr<LogEntryStore> store) : _log(store)
{

}

void LogReaderServiceImpl::AddLogListener(LogListener listener)
{
  std::lock_guard<std::mutex> lock(_listener_lock);
  _log_listeners.push_front(listener);
}

std::vector<LogEntry> LogReaderServiceImpl::GetLog()
{
  return _log->entries();
}

void LogReaderServiceImpl::RemoveLogListener(LogListener listener)
{
  std::lock_guard<std::mutex> lock(_listener_lock);
  _log_listeners.remove(listener);
}

void LogReaderServiceImpl::Logged(const LogEntry& entry)
{
  _log->insert(entry);
  for(auto const& listener : _log_listeners)
  {
    try
    {
      listener(entry);
    }
    catch(...)
    { /* swallow any exceptions */}
  }
}

bool operator==(const LogListener& l1, const LogListener& l2)
{
  return typeid(l1) == typeid(l2);
}

} // namespace logservice

} // namespace us
