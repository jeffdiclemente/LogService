
#ifndef ACTIVATOR_H__
#define ACTIVATOR_H__

#include "usBundleActivator.h"
#include "usBundleContext.h"

namespace us {

namespace logservice {

class LogServiceActivator : public BundleActivator
{
public:
  LogServiceActivator() = default;
  virtual ~LogServiceActivator() = default;

  void Start(BundleContext* bc);
  void Stop(BundleContext* bc);

};

} // namespace logservice

} // namespace us

#endif // ACTIVATOR_H__
