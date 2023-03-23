cmake_minimum_required (VERSION 3.8)

project (Glad)
file (GLOB_RECURSE GladSrc Inc/**.* Src/**.*)
add_library (Glad STATIC ${GladSrc})
target_include_directories (Glad PUBLIC Inc)