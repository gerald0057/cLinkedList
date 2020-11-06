cmake_minimum_required(VERSION 3.0.0)
project(cDulLinkedList VERSION 0.1.0)

include_directories(
    .
)

aux_source_directory(
    . FILE_SRC
)

add_executable(cDulLinkedList ${FILE_SRC})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
