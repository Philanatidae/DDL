# Define test executable
add_executable(DDL-tests)
target_link_libraries(DDL-tests PRIVATE
    Catch2::Catch2
    DDL)
add_subdirectory(src)
