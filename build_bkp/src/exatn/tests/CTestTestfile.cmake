# CMake generated Testfile for 
# Source directory: /home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/exatn/tests
# Build directory: /home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/build/src/exatn/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(ServiceRegistryTester "ServiceRegistryTester")
set_tests_properties(ServiceRegistryTester PROPERTIES  _BACKTRACE_TRIPLES "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/tpls/CMakeLists.txt;48;add_test;/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/exatn/tests/CMakeLists.txt;2;exatn_add_test;/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/exatn/tests/CMakeLists.txt;0;")
add_test(NumServerTester "NumServerTester")
set_tests_properties(NumServerTester PROPERTIES  _BACKTRACE_TRIPLES "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/tpls/CMakeLists.txt;67;add_test;/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/exatn/tests/CMakeLists.txt;6;exatn_add_mpi_test;/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/exatn/tests/CMakeLists.txt;0;")
subdirs("testplugin")
