set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDART_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-pedantic -Wall -Wextra")

cmake_path(SET LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib1")
include_directories(
        ${LIB_DIR}
)

#add_subdirectory("12/shape_primitives")
add_subdirectory("07/calculator")