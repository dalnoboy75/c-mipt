set(TARGET "calculator")
project (${TARGET} LANGUAGES CXX)
add_executable(
    ${TARGET}
    calculator.cpp
)
install (TARGETS ${TARGET})
