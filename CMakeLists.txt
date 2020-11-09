cmake_minimum_required(VERSION 3.0.0)
project(Projet_LO21 VERSION 0.1.0)

include(CTest)
enable_testing()

set(SOURCES
    src/main.c
)

set(HEADERS

)

add_executable(Projet_LO21 ${SOURCES} ${HEADERS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
