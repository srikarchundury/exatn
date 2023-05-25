#----------------------------------------------------------------
# Generated CMake target import file for configuration "RELEASE".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "usResourceCompiler" for configuration "RELEASE"
set_property(TARGET usResourceCompiler APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(usResourceCompiler PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/usResourceCompiler4"
  )

list(APPEND _cmake_import_check_targets usResourceCompiler )
list(APPEND _cmake_import_check_files_for_usResourceCompiler "${_IMPORT_PREFIX}/bin/usResourceCompiler4" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
