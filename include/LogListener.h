
#ifndef LOG_LISTENER_H__
#define LOG_LISTENER_H__

#include "LogEntry.h"

#include <functional>

namespace us { namespace logservice {

  typedef std::function<void(const LogEntry&)> LogListener;

  // @todo implement. forward_list needs a comparator function
  bool operator==(const LogListener&, const LogListener&);

} // namespace us

} // namespace logservice

#endif // LOG_LISTENER_H__
