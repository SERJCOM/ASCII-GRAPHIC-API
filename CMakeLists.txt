cmake_minimum_required(VERSION 3.0.0)
project(asciiEngine VERSION 0.1.0)

set(GLM "D:/prog/glm-0.9.9.8")

add_executable(asciiEngine src/main.cpp )

target_include_directories(asciiEngine PUBLIC
    ${GLM}
    ${CMAKE_SOURCE_DIR}/include
)

