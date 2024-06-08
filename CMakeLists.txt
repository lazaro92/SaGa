cmake_minimum_required(VERSION 3.28)
project(SaGa
  LANGUAGES CXX
  VERSION 1.0
)

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
  src/Player.cpp
  src/SceneNode.cpp
  src/SoundPlayer.cpp
  src/SpriteNode.cpp
  src/State.cpp
  src/StateStack.cpp
  src/Utility.cpp
  src/World.cpp
)

target_include_directories(SaGa_exe
  PRIVATE
  "include"
)
  
target_link_libraries(SaGa_exe PRIVATE sfml-graphics sfml-audio)

add_custom_command(TARGET SaGa_exe PRE_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
  ${CMAKE_SOURCE_DIR}/media/ $<TARGET_FILE_DIR:SaGa_exe>/media
)