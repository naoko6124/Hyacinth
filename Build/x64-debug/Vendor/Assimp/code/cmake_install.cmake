# Install script for directory: C:/dev/Hyacinth/Vendor/Assimp/code

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/dev/Hyacinth/Install/x64-debug")
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

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "libassimp5.2.5-dev" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/dev/Hyacinth/Build/x64-debug/Vendor/Assimp/lib/Debug/assimp-vc143-mtd.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/dev/Hyacinth/Build/x64-debug/Vendor/Assimp/lib/Release/assimp-vc143-mt.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/dev/Hyacinth/Build/x64-debug/Vendor/Assimp/lib/MinSizeRel/assimp-vc143-mt.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/dev/Hyacinth/Build/x64-debug/Vendor/Assimp/lib/RelWithDebInfo/assimp-vc143-mt.lib")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "libassimp5.2.5" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/dev/Hyacinth/Build/x64-debug/Vendor/Assimp/bin/Debug/assimp-vc143-mtd.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/dev/Hyacinth/Build/x64-debug/Vendor/Assimp/bin/Release/assimp-vc143-mt.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/dev/Hyacinth/Build/x64-debug/Vendor/Assimp/bin/MinSizeRel/assimp-vc143-mt.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/dev/Hyacinth/Build/x64-debug/Vendor/Assimp/bin/RelWithDebInfo/assimp-vc143-mt.dll")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "assimp-dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp" TYPE FILE FILES
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/anim.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/aabb.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/ai_assert.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/camera.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/color4.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/color4.inl"
    "C:/dev/Hyacinth/Build/x64-debug/Vendor/Assimp/code/../include/assimp/config.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/ColladaMetaData.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/commonMetaData.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/defs.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/cfileio.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/light.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/material.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/material.inl"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/matrix3x3.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/matrix3x3.inl"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/matrix4x4.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/matrix4x4.inl"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/mesh.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/ObjMaterial.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/pbrmaterial.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/GltfMaterial.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/postprocess.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/quaternion.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/quaternion.inl"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/scene.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/metadata.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/texture.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/types.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/vector2.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/vector2.inl"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/vector3.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/vector3.inl"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/version.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/cimport.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/AssertHandler.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/importerdesc.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/Importer.hpp"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/DefaultLogger.hpp"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/ProgressHandler.hpp"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/IOStream.hpp"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/IOSystem.hpp"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/Logger.hpp"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/LogStream.hpp"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/NullLogger.hpp"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/cexport.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/Exporter.hpp"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/DefaultIOStream.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/DefaultIOSystem.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/ZipArchiveIOSystem.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/SceneCombiner.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/fast_atof.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/qnan.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/BaseImporter.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/Hash.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/MemoryIOWrapper.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/ParsingUtils.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/StreamReader.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/StreamWriter.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/StringComparison.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/StringUtils.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/SGSpatialSort.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/GenericProperty.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/SpatialSort.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/SkeletonMeshBuilder.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/SmallVector.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/SmoothingGroups.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/SmoothingGroups.inl"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/StandardShapes.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/RemoveComments.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/Subdivision.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/Vertex.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/LineSplitter.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/TinyFormatter.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/Profiler.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/LogAux.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/Bitmap.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/XMLTools.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/IOStreamBuffer.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/CreateAnimMesh.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/XmlParser.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/BlobIOSystem.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/MathFunctions.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/Exceptional.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/ByteSwapper.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/Base64.hpp"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "assimp-dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp/Compiler" TYPE FILE FILES
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/Compiler/pushpack1.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/Compiler/poppack1.h"
    "C:/dev/Hyacinth/Vendor/Assimp/code/../include/assimp/Compiler/pstdint.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "C:/dev/Hyacinth/Build/x64-debug/Vendor/Assimp/code/Debug/assimp-vc143-mtd.pdb")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "C:/dev/Hyacinth/Build/x64-debug/Vendor/Assimp/code/RelWithDebInfo/assimp-vc143-mt.pdb")
  endif()
endif()

