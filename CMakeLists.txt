cmake_minimum_required(VERSION 3.16.3)
project(CopyTextFromVideo)

find_package(OpenCV REQUIRED)
set(Tesseract_LIBS tesseract)
find_package(Threads)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(CopyTextFromVideo
    src/main.cpp
    src/LCS.cpp
    src/LCS.hpp
    src/OpticalCharacterRecognition.cpp
    src/OpticalCharacterRecognition.hpp
    src/TextProvider.cpp
    src/TextProvider.hpp
    src/FrameProvider.cpp
    src/FrameProvider.hpp
)


target_link_libraries(CopyTextFromVideo
    ${OpenCV_LIBS}
    ${Tesseract_LIBS}
    ${CMAKE_THREAD_LIBS_INIT}
)