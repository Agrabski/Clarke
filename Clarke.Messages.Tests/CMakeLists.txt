find_package(GTest CONFIG REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})

add_executable(Clarke.Messages.Tests "Clarke.Messages.Tests.cpp")
target_link_libraries(Clarke.Messages.Tests PRIVATE GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)

add_test(Clarke.Messages.Tests Clarke.Messages.Tests)
