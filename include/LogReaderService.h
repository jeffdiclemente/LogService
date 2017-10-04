#ifndef LOG_READER_SERVICE_H__
#define LOG_READER_SERVICE_H__

#include "usLogServiceExport.h"

#include "LogEntry.h"
#include "LogListener.h"

#include <vector>

namespace us { namespace logservice {

class US_LogService_EXPORT LogReaderService
{
public:
  virtual ~LogReaderService();

  virtual void AddLogListener(LogListener listener) = 0;
  virtual std::vector<LogEntry> GetLog() = 0;
  virtual void RemoveLogListener(LogListener listener) = 0;
};

} // namespace logservice

} // namespace us

#endif // LOG_READER_SERVICE_H__
