enable_testing()
find_package(GTest REQUIRED)

add_executable(basic_tests tests/basic_tests.cpp)
target_link_libraries(basic_tests GTest::gtest GTest::gtest_main pthread)

add_test(NAME basic_tests COMMAND basic_tests)
