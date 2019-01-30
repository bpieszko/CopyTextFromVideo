cmake_minimum_required(VERSION 3.5.1)
project(CopyTextFromVideo)

find_package(OpenCV REQUIRED)
set(Tesseract_LIBS tesseract)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include)

file(GLOB SOURCES source/*.cpp)

add_executable(CopyTextFromVideo ${SOURCES})
target_link_libraries(CopyTextFromVideo ${OpenCV_LIBS} ${Tesseract_LIBS})