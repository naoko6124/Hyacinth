cmake_minimum_required (VERSION 3.8)

add_subdirectory (Vendor/Glad)
add_subdirectory (Vendor/Glm)

project (Hyacinth)
file (GLOB_RECURSE HyacinthSrc Hyacinth/**.*)
add_executable (Hyacinth ${HyacinthSrc})
target_include_directories (Hyacinth PUBLIC Hyacinth)
target_link_libraries (Hyacinth PUBLIC Glad Glm)

project (HyaTool)
file (GLOB_RECURSE HyaToolSrc HyaTool/**.*)
add_executable (HyaTool ${HyaToolSrc})
target_include_directories (HyaTool PUBLIC HyaTool)