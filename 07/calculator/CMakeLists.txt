set(TARGET "calculator")
project (${TARGET} LANGUAGES CXX)
add_executable(
    ${TARGET}
    calculator.cpp
    calculating.cpp
    calculating.h
    const.h
    token.cpp
    token.h
    variable.cpp
    variable.h
)
install (TARGETS ${TARGET})
