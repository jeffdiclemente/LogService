
#include "LogEntry.h"
#include "LogEntryPrivate.h"

namespace cppmicroservices { namespace logservice {


LogEntryPrivate::LogEntryPrivate(Bundle bundle,
                            const std::exception_ptr ex,
                            const SeverityLevel& level,
                            const std::string& message,
                            const ServiceReferenceU& sr,
                            long t)
                            : _bundle(bundle),
                              _sr(sr),
                              _message(message),
                              _ex(ex),
                              _level(level),
                              _time(t)
{

}

} // namespace logservice

} // namespace cppmicroservices
