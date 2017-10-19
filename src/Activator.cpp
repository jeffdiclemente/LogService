
#include "Activator.h"

#include "LogService.h"
#include "LogReaderService.h"

#include "LogServiceImpl.h"
#include "LogReaderServiceImpl.h"

#include <memory>

namespace cppmicroservices { namespace logservice {

void LogServiceActivator::Start(BundleContext bc)
{
  // configuration defaults:
  //  maxsize = 0 (no maximum)
  //  storedebug = false (don't store debug logs)
  Any max_size = bc.GetBundle().GetProperty(std::string("org.cppmicroservices.log.maxsize"));
  if (max_size.Empty()) {
    max_size = Any(0);
  }
  Any storedebug = bc.GetBundle().GetProperty(std::string("org.cppmicroservices.log.storedebug"));
  if (storedebug.Empty()) {
    storedebug = Any(false);
  }
  auto reader = std::make_shared<LogReaderServiceImpl>(std::make_shared<LogEntryStore>(0, any_cast<bool>(storedebug)));
  bc.RegisterService<LogReaderService>(reader);
  bc.RegisterService<LogService>(std::make_shared<LogServiceImpl>(reader));
}

void LogServiceActivator::Stop(BundleContext )
{

}

} // namespace logservice

} // namespace cppmicroservices

US_EXPORT_BUNDLE_ACTIVATOR(cppmicroservices::logservice::LogServiceActivator)
