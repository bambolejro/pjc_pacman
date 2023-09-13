cmake_minimum_required(VERSION 3.25)
project(PJC_pacman)

set(CMAKE_CXX_STANDARD 17)

add_executable(PJC_pacman main.cpp DrawMap.cpp Headers/DrawMap.h Headers/Global.h Pacman.cpp Headers/Pacman.h Headers/Collider.h Collider.cpp SketchConvertion.cpp Headers/SketchConversion.h Headers/DrawPacman.h DrawPacman.cpp Game.cpp Headers/Ghost.h Ghost.cpp Headers/DrawGhost.h DrawGhost.cpp GhostManager.cpp Headers/GhostManager.h GhostSelector.cpp GhostCollider.cpp Headers/GhostCollider.h DrawPointsState.cpp Headers/DrawPointsState.h MovingObject.cpp Headers/MovingObject.h Headers/DrawMovingObject.h DrawMovingObject.cpp Headers/DrawGhostTmp.h Headers/DrawPacmanTmp.h DrawPacmanTemp.cpp DrawGhostTmp.cpp)


include_directories(/usr/include c:/SFML/include)

set(SFML_ROOT c:/SFML)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(PJC_pacman ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

# Copy dlls to build
if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
    file(GLOB MINGW_DEP_DLLS "C:/mingw64/bin/*.dll")
    file(COPY ${MINGW_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()