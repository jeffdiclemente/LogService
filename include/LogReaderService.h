#ifndef LOG_READER_SERVICE_H__
#define LOG_READER_SERVICE_H__

#include "usLogServiceExport.h"

#include "LogEntry.h"
#include "LogListener.h"

#include <vector>

namespace cppmicroservices { namespace logservice {

class US_LogService_EXPORT LogReaderService
{
public:
  virtual ~LogReaderService();

  // @todo: fix Add/RemoveLogListener, we can't remove based on LogListener object.
  virtual void AddLogListener(LogListener listener) = 0;
  virtual std::vector<LogEntry> GetLog() = 0;
  virtual void RemoveLogListener(LogListener listener) = 0;
};

} // namespace logservice

} // namespace cppmicroservices

#endif // LOG_READER_SERVICE_H__
