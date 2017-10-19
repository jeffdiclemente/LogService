#ifndef LOG_SERVICE_H__
#define LOG_SERVICE_H__

#include "usLogServiceExport.h"

#include "cppmicroservices/ServiceReference.h"

#include <exception>
#include <string>

namespace cppmicroservices { namespace logservice {

enum class SeverityLevel : unsigned int
{
  LOG_ERROR = 1,
  LOG_WARNING = 2,
  LOG_INFO = 3,
  LOG_DEBUG = 4
};

class US_LogService_EXPORT LogService
{
public:
  virtual ~LogService();

  virtual void Log(SeverityLevel level, const std::string& message) = 0;
  virtual void Log(SeverityLevel level, const std::string& message, std::exception_ptr ex) = 0;
  virtual void Log(ServiceReferenceU sr, SeverityLevel level, const std::string& message) = 0;
  virtual void Log(ServiceReferenceU sr, SeverityLevel level, const std::string& message, std::exception_ptr ex) = 0;
};


} // namespace logservice

} // namespace cppmicroservices

#endif // LOG_SERVICE_H__
