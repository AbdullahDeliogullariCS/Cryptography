cmake_minimum_required(VERSION 3.13)

set(SOURCES
        test.cpp)

add_executable(cryptography_test ${SOURCES})

target_link_libraries(cryptography_test PUBLIC
        gtest_main
        core)

add_test(
        NAME cryptography_test
        COMMAND cryptography_test)

