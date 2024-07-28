add_library(libcjstr cjstr.c)

add_executable(cjstr_app main.c)

target_link_libraries(cjstr_app libcjstr)
