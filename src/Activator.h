
#ifndef ACTIVATOR_H__
#define ACTIVATOR_H__

#include "cppmicroservices/BundleActivator.h"
#include "cppmicroservices/BundleContext.h"

namespace cppmicroservices {

namespace logservice {

class LogServiceActivator : public BundleActivator
{
public:
  LogServiceActivator() = default;
  virtual ~LogServiceActivator() = default;

  void Start(BundleContext bc);
  void Stop(BundleContext bc);

};

} // namespace logservice

} // namespace cppmicroservices

#endif // ACTIVATOR_H__
