cmake_minimum_required(VERSION 3.5)
project(seetface LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "D:/Codding/Qt/6.9.1/mingw_64")
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS Widgets Network REQUIRED)

aux_source_directory(./src srcs)

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

add_executable(${PROJECT_NAME}
    WIN32
    ${srcs}
    resources.qrc
)

target_include_directories(${PROJECT_NAME} PRIVATE
    D:/Codding/cdd/opencv/opencv46/include
    D:/Codding/cdd/SeetaFace/include
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Widgets
    Qt6::Network
    D:/Codding/cdd/opencv/opencv46/x64/mingw/lib/libopencv_core460d.dll.a
    D:/Codding/cdd/opencv/opencv46/x64/mingw/lib/libopencv_imgproc460d.dll.a
    D:/Codding/cdd/opencv/opencv46/x64/mingw/lib/libopencv_imgcodecs460d.dll.a
    D:/Codding/cdd/opencv/opencv46/x64/mingw/lib/libopencv_highgui460d.dll.a
    D:/Codding/cdd/opencv/opencv46/x64/mingw/lib/libopencv_videoio460d.dll.a
    D:/Codding/cdd/opencv/opencv46/x64/mingw/lib/libopencv_objdetect460d.dll.a

    D:/Codding/cdd/SeetaFace/lib/libSeetaFaceDetector.dll.a
    D:/Codding/cdd/SeetaFace/lib/libSeetaFaceLandmarker.dll.a
    D:/Codding/cdd/SeetaFace/lib/libSeetaFaceRecognizer.dll.a
    D:/Codding/cdd/SeetaFace/lib/libSeetaFaceTracker.dll.a
    D:/Codding/cdd/SeetaFace/lib/libSeetaNet.dll.a
    D:/Codding/cdd/SeetaFace/lib/libSeetaQualityAssessor.dll.a
)
