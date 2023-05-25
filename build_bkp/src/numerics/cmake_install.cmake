# Install script for directory: /home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics

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
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/basis_vector.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/contraction_seq_optimizer.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/contraction_seq_optimizer_cutnn.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/contraction_seq_optimizer_dummy.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/contraction_seq_optimizer_factory.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/contraction_seq_optimizer_greed.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/contraction_seq_optimizer_heuro.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/contraction_seq_optimizer_metis.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/functor_diag_rank.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/functor_init_dat.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/functor_init_delta.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/functor_init_file.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/functor_init_proj.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/functor_init_rnd.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/functor_init_unity.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/functor_init_val.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/functor_isnan.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/functor_isometrize.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/functor_maxabs.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/functor_norm1.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/functor_norm2.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/functor_print.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/functor_scale.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/metis_graph.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/network_build_factory.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/network_builder.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/network_builder_mps.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/network_builder_peps.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/network_builder_ttn.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/packable.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/space_basis.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/space_register.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/spaces.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/tensor.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/tensor_basic.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/tensor_composite.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/tensor_connected.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/tensor_expansion.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/tensor_leg.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/tensor_network.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/tensor_op_add.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/tensor_op_allreduce.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/tensor_op_broadcast.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/tensor_op_contract.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/tensor_op_create.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/tensor_op_decompose_svd2.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/tensor_op_decompose_svd3.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/tensor_op_destroy.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/tensor_op_factory.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/tensor_op_fetch.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/tensor_op_insert.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/tensor_op_orthogonalize_mgs.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/tensor_op_orthogonalize_svd.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/tensor_op_slice.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/tensor_op_transform.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/tensor_op_upload.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/tensor_operation.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/tensor_operator.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/tensor_range.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/tensor_shape.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/tensor_signature.hpp"
    "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/src/numerics/tensor_symbol.hpp"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libexatn-numerics.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libexatn-numerics.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libexatn-numerics.so"
         RPATH "$ORIGIN/../lib:/home/schundu3/projects/ornl_tools/build/exatn/lib:/usr/lib/x86_64-linux-gnu/openblas-pthread")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/build/src/numerics/libexatn-numerics.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libexatn-numerics.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libexatn-numerics.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libexatn-numerics.so"
         OLD_RPATH "/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/build/src/utils:/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/build/tpls/metis/libmetis:/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/build/tpls/metis/GKlib:/home/schundu3/projects/ornl_tools/build/exatn/lib:/usr/lib/x86_64-linux-gnu/openblas-pthread:"
         NEW_RPATH "$ORIGIN/../lib:/home/schundu3/projects/ornl_tools/build/exatn/lib:/usr/lib/x86_64-linux-gnu/openblas-pthread")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libexatn-numerics.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/schundu3/projects/ornl_tools/ORNL_QIS_Stack/exatn/build/src/numerics/tests/cmake_install.cmake")

endif()

