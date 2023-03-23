cmake_minimum_required (VERSION 3.8)

project (Glm)
file (GLOB_RECURSE GlmSrc Inc/**.* Src/**.*)
add_library (Glm STATIC ${GlmSrc})
target_include_directories (Glm PUBLIC Inc)