#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "tinygltf::tinygltf" for configuration "Debug"
set_property(TARGET tinygltf::tinygltf APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(tinygltf::tinygltf PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/tinygltfd.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/tinygltfd.dll"
  )

list(APPEND _cmake_import_check_targets tinygltf::tinygltf )
list(APPEND _cmake_import_check_files_for_tinygltf::tinygltf "${_IMPORT_PREFIX}/lib/tinygltfd.lib" "${_IMPORT_PREFIX}/bin/tinygltfd.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
