#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "tinygltf::tinygltf" for configuration "RelWithDebInfo"
set_property(TARGET tinygltf::tinygltf APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(tinygltf::tinygltf PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/tinygltf.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/tinygltf.dll"
  )

list(APPEND _cmake_import_check_targets tinygltf::tinygltf )
list(APPEND _cmake_import_check_files_for_tinygltf::tinygltf "${_IMPORT_PREFIX}/lib/tinygltf.lib" "${_IMPORT_PREFIX}/bin/tinygltf.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
