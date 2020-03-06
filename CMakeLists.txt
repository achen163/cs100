CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(rshell
   src/main.cpp
   src/parser.cpp
   src/cmd.cpp
   src/andConnector.cpp
   src/semiConnector.cpp
   src/orConnector.cpp
   src/pipeConnector.cpp
)

ADD_EXECUTABLE(test
   unit_tests/unit_test.cpp	
   src/parser.cpp
   src/cmd.cpp
   src/andConnector.cpp
   src/semiConnector.cpp
   src/orConnector.cpp
   src/pipeConnector.cpp
)


SET(DEBUG_FLAG "-g")
add_definitions(${DEBUG_FLAG})
TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
