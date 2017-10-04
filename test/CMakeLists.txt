
# set(_bundle_name logservice)
# set(GTEST_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/external/gtest)
# set(GTEST_VERSION master)
#
# include(ExternalProject)
# ExternalProject_Add(gtest-${GTEST_VERSION}
#                     PREFIX ${GTEST_PREFIX}
#                     GIT_REPOSITORY https://github.com/google/googletest.git
#                     GIT_TAG ${GTEST_VERSION}
#                     CMAKE_ARGS -DCMAKE_BUILD_TYPE=Release -DBUILD_SHARED_LIBS:BOOL=OFF -DCMAKE_INSTALL_PREFIX:PATH=${GTEST_PREFIX})
#
# set(GTEST_INCLUDE_DIRS ${GTEST_PREFIX}/include)
# set(GTEST_BOTH_LIBRARIES
#     ${GTEST_PREFIX}/lib/${CMAKE_STATIC_LIBRARY_PREFIX}gtest${CMAKE_STATIC_LIBRARY_SUFFIX}
#     ${GTEST_PREFIX}/lib/${CMAKE_STATIC_LIBRARY_PREFIX}gtest_main${CMAKE_STATIC_LIBRARY_SUFFIX})
#
# enable_testing()
#
# include_directories(${GTEST_INCLUDE_DIRS})
#
# set(_unittest_srcs
#     TestLogEntry.cpp
#     TestLogEntryStore.cpp
#     TestLogReaderService.cpp
#     TestLogService.cpp)
#
# add_executable(${_bundle_name}_unittests ${_unittest_srcs})
# target_link_libraries(${_bundle_name}_unittests ${_bundle_name} ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
#
# # Create a libgtest target to be used as a dependency by test programs
# add_dependencies(${_bundle_name}_unittests gtest-${GTEST_VERSION} LogService)
#
# add_test(${_bundle_name}_unittests ${_bundle_name}_unittests)
