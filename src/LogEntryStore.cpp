
#include "LogEntryStore.h"

namespace cppmicroservices { namespace logservice {

void LogEntryStore::insert(const LogEntry& entry)
{
  if(!_log_debug_entries && SeverityLevel::LOG_DEBUG == entry.GetLevel()) return;
  std::lock_guard<std::mutex> lock(_store_lock);
  _store.push_back(entry);
}

std::vector<LogEntry> LogEntryStore::entries() { return std::vector<LogEntry>(_store.begin(), _store.end()); }

} // namespace cppmicroservices

} // namespace logservice
