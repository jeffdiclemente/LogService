
#ifndef LOG_ENTRY_STORE_H__
#define LOG_ENTRY_STORE_H__

#include "LogEntry.h"

#include <mutex>
#include <deque>
#include <vector>

namespace us { namespace logservice {

class LogEntryStore
{
public:
  // @todo define properties to configure the max # of log entries to keep
  // and whether or not debug logs are kept.
  // org.cppmicroservices.log.maxsize
  // org.cppmicroservices.log.storedebug
  LogEntryStore(unsigned long max_entries = 0, bool log_debug = false)
    : _max_store_entries(max_entries), _log_debug_entries(log_debug)
    {}
  ~LogEntryStore() {}

  LogEntryStore(const LogEntryStore&) = delete;
  LogEntryStore& operator=(const LogEntryStore&) = delete;

  void insert(const LogEntry& entry);
  std::vector<LogEntry> entries();

private:
  std::mutex _store_lock;
  std::deque<LogEntry> _store;
  unsigned long _max_store_entries;
  bool _log_debug_entries;
};

} // namespace us

} // namespace logservice

#endif  // LOG_ENTRY_STORE_H__
