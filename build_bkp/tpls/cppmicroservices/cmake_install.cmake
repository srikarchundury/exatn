# Install script for directory: /home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/tpls/cppmicroservices

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
    set(CMAKE_INSTALL_CONFIG_NAME "RELEASE")
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
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cppmicroservices4/cmake/CppMicroServicesTargets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cppmicroservices4/cmake/CppMicroServicesTargets.cmake"
         "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/build/tpls/cppmicroservices/CMakeFiles/Export/07c78fe876f0ca29ad434080522b336f/CppMicroServicesTargets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cppmicroservices4/cmake/CppMicroServicesTargets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cppmicroservices4/cmake/CppMicroServicesTargets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cppmicroservices4/cmake" TYPE FILE FILES "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/build/tpls/cppmicroservices/CMakeFiles/Export/07c78fe876f0ca29ad434080522b336f/CppMicroServicesTargets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cppmicroservices4/cmake" TYPE FILE FILES "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/build/tpls/cppmicroservices/CMakeFiles/Export/07c78fe876f0ca29ad434080522b336f/CppMicroServicesTargets-release.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cppmicroservices4/cmake" TYPE FILE FILES
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/tpls/cppmicroservices/cmake/BundleInit.cpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/tpls/cppmicroservices/cmake/CMakeResourceDependencies.cpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/tpls/cppmicroservices/cmake/usFunctionGenerateBundleInit.cmake"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/tpls/cppmicroservices/cmake/usFunctionAddResources.cmake"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/tpls/cppmicroservices/cmake/usFunctionEmbedResources.cmake"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/tpls/cppmicroservices/cmake/usFunctionGetResourceSource.cmake"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/tpls/cppmicroservices/cmake/usFunctionCheckResourceLinking.cmake"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/tpls/cppmicroservices/cmake/usFunctionCheckCompilerFlags.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cppmicroservices4/cppmicroservices" TYPE FILE FILES "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/build/tpls/cppmicroservices/include/cppmicroservices/GlobalConfig.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "sdk" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cppmicroservices4/cmake" TYPE FILE FILES
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/build/tpls/cppmicroservices/CMakeFiles/CppMicroServicesConfig.cmake"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/build/tpls/cppmicroservices/CppMicroServicesConfigVersion.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/build/tpls/cppmicroservices/tools/rc/cmake_install.cmake")
  include("/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/build/tpls/cppmicroservices/util/cmake_install.cmake")
  include("/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/build/tpls/cppmicroservices/framework/cmake_install.cmake")

endif()

