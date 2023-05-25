# Install script for directory: /home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/exatn

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/schundu3/projects/ornl_tools/build/exatn")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/exatn" TYPE FILE FILES
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/exatn/Identifiable.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/exatn/ServiceRegistry.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/exatn/eigensolver.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/exatn/exatn.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/exatn/exatn_numerics.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/exatn/exatn_service.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/exatn/linear_solver.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/exatn/num_server.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/exatn/optimizer.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/exatn/quantum.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/exatn/reconstructor.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/exatn/remapper.hpp"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libexatn.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libexatn.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libexatn.so"
         RPATH "$ORIGIN:/home/schundu3/projects/ornl_tools/build/exatn/lib:/usr/lib/x86_64-linux-gnu/openblas-pthread")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/build/src/exatn/libexatn.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libexatn.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libexatn.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libexatn.so"
         OLD_RPATH "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/build/src/runtime:/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/build/src/runtime/graph:/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/build/tpls/cppmicroservices/lib:/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/build/src/numerics:/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/build/src/utils:/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/build/tpls/metis/libmetis:/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/build/tpls/metis/GKlib:/home/schundu3/projects/ornl_tools/build/exatn/lib:/usr/lib/x86_64-linux-gnu/openblas-pthread:"
         NEW_RPATH "$ORIGIN:/home/schundu3/projects/ornl_tools/build/exatn/lib:/usr/lib/x86_64-linux-gnu/openblas-pthread")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libexatn.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/build/src/exatn/tests/cmake_install.cmake")

endif()

