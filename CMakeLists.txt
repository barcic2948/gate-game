cmake_minimum_required(VERSION 3.0.0)
project(main VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(main
    src/main.cpp
    src/Engine.cpp

    src/StateManager/StatePlaying.cpp

    src/ResourceManager/ResourceHolder.cpp

    src/Utils/FileUtil.cpp
    src/Utils/FPSCounter.cpp
    src/Utils/SaveData.cpp

    src/GUI/Widget.cpp
    src/GUI/Button.cpp
    src/GUI/AutoMenu.cpp
)


target_link_libraries(main sfml-graphics sfml-audio)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)


set_property(TARGET main PROPERTY CXX_STANDARD 20)