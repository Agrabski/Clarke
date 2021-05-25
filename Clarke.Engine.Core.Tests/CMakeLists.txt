find_package(GTest CONFIG REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})
add_executable(Clarke.Engine.Core.Tests   "SerializationTests.cpp")

target_link_libraries(Clarke.Engine.Core.Tests PRIVATE "Clarke.Messages")
target_link_libraries(Clarke.Engine.Core.Tests PRIVATE "Clarke.Engine.Core")
target_link_libraries(Clarke.Engine.Core.Tests PRIVATE GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)

add_test(Clarke.Engine.Core.Tests Clarke.Engine.Core.Tests)
