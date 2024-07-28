cmake_minimum_required(VERSION 3.26)
project(cjstr C)

add_executable(cjstr ../c/cjstr.c)
set_target_properties(
        cjstr
        PROPERTIES
        LINK_FLAGS "-s FILESYSTEM=0 -s ALLOW_MEMORY_GROWTH=1 -s DEFAULT_TO_CXX=0 -s MODULARIZE -s EXPORTED_RUNTIME_METHODS=stringToUTF32,POINTER_SIZE,setValue,UTF32ToString,stackAlloc,stackSave,stackRestore -O3"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}"
)
