cmake_minimum_required(VERSION 3.8)

set(PROJECT RefactoringLibrary)


set(SRC_PAGES
    Prime.cpp
)

set(SOURCES
    ${SRC_PAGES}
)

add_library(${PROJECT} STATIC ${SOURCES})

set(CLIENT_PROJECT client)
set(CLIENT_SOURCES
    main.cpp
)

add_executable(${CLIENT_PROJECT} ${CLIENT_SOURCES})

target_link_libraries(${CLIENT_PROJECT}
    PUBLIC
        RefactoringLibrary 
)
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