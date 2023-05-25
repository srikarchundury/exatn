

set(US_Framework_LIBRARIES CppMicroServices)
set(US_Framework_RUNTIME_LIBRARY_DIRS "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/build/tpls/cppmicroservices/bin")

if(NOT TARGET CppMicroServices)
  include("${CMAKE_CURRENT_LIST_DIR}/usFrameworkTargets.cmake")
endif()
