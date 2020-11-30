set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

project(lookup_table)

add_library(${PROJECT_NAME} SHARED
    "src/lookup_table.cpp"
    "include/lookup_table.h")

target_include_directories(${PROJECT_NAME}
    PUBLIC
    "include")
