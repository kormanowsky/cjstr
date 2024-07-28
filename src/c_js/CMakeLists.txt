cmake_minimum_required(VERSION 3.26)
project(cjstr_js C)

add_executable(cjstr ../c/cjstr.c)

set_target_properties(
        cjstr
        PROPERTIES
        LINK_FLAGS "-s MODULARIZE -s WASM_ASYNC_COMPILATION=0 -s INVOKE_RUN=0 -s FILESYSTEM=0 -s ALLOW_MEMORY_GROWTH=1 -s DEFAULT_TO_CXX=0 -s EXPORTED_RUNTIME_METHODS=stringToUTF32,POINTER_SIZE,setValue,UTF32ToString,stackAlloc,stackSave,stackRestore -O3"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}"
)
