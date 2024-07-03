cmake_minimum_required(VERSION 3.28)
project(SaGa
  LANGUAGES CXX
  VERSION 1.0
)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(TargetAddExtraWarnings)

add_subdirectory(dependencies)

add_executable(SaGa_exe
  src/Application.cpp
  src/Character.cpp
  src/Command.cpp
  src/CommandQueue.cpp
  src/DataTables.cpp
  src/Entity.cpp
  src/GameState.cpp
  src/main.cpp
  src/MusicPlayer.cpp
  src/PauseState.cpp
  src/Player.cpp
  src/SceneNode.cpp
  src/SelectMapState.cpp
  src/SoundPlayer.cpp
  src/SpriteNode.cpp
  src/State.cpp
  src/StateStack.cpp
  src/TilesetNode.cpp
  src/Utility.cpp
  src/World.cpp

  src/GUI/Component.cpp
  src/GUI/Option.cpp
  src/GUI/Panel.cpp
  src/GUI/PanelChoices.cpp
  src/GUI/PanelText.cpp
)

set_target_properties(SaGa_exe PROPERTIES
    CXX_STANDARD 20
    CXX_EXTENSIONS OFF
)

target_add_extra_warnings(SaGa_exe)

target_include_directories(SaGa_exe
  PRIVATE
  "include"
)
  
target_link_libraries(SaGa_exe PRIVATE sfml-graphics sfml-audio)

add_custom_command(TARGET SaGa_exe PRE_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
  ${CMAKE_SOURCE_DIR}/media/ $<TARGET_FILE_DIR:SaGa_exe>/media
)