
set(_bundle_name logservice)
set(_interface_name ilogservice)

set(_${_bundle_name}_srcs
    src/Activator.cpp
    src/LogReaderServiceImpl.cpp
    src/LogServiceImpl.cpp
    src/LogEntryStore.cpp)

set(_${_bundle_name}_private_headers
    src/Activator.h
    src/LogEntryPrivate.h
    src/LogEntryStore.h
    src/LogReaderServiceImpl.h
    src/LogServiceImpl.h)

set(_${_interface_name}_public_headers
    include/LogEntry.h
    include/LogListener.h
    include/LogReaderService.h
    include/LogService.h)

set(_${_interface_name}_srcs
    src/LogEntry.cpp
    src/LogEntryPrivate.cpp
    src/LogReaderService.cpp
    src/LogService.cpp)

# Configure the bundles manifest.json file
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/resources/manifest.json.in
               ${CMAKE_CURRENT_BINARY_DIR}/resources/manifest.json)

# Create the bundle
usMacroCreateBundle(LogService
  VERSION "0.1.0"
  TARGET org_cppmicroservices_logservice
  DEPENDS Framework
  LINK_LIBRARIES ${_link_libraries}
  SOURCES ${_${_bundle_name}_srcs}
  PUBLIC_HEADERS ${_${_interface_name}_public_headers}
  PRIVATE_HEADERS ${_${_bundle_name}_private_headers}
  BINARY_RESOURCES manifest.json)

# Create the "interface" library to which clients link
# This is NOT a bundle and only contains type information
# required by clients using the services exported by
# the bundle.
usMacroCreateInterface(ILogService
  VERSION "0.1.0"
  TARGET org_cppmicroservices_logservice_interface
  LINK_LIBRARIES ${_link_libraries}
  SOURCES ${_${_interface_name}_srcs}
  PUBLIC_HEADERS ${_${_interface_name}_public_headers})
