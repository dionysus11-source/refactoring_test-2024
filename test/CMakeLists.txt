set(PROJECT ChatClientTest)

set(SRC_COMMON
test.cpp
)

set(SOURCES
    ${SRC_COMMON}
)

add_executable(${PROJECT} ${SOURCES})

target_link_libraries(${PROJECT}
    PUBLIC
    gtest
    gtest_main
    RefactoringLibrary 

)

add_test(
    NAME ${PROJECT}
    COMMAND ${PROJECT}
)
