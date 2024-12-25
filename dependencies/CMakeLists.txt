include(FetchContent)

FetchContent_Declare(
  sfml
  GIT_REPOSITORY "https://github.com/SFML/SFML"
  GIT_TAG 7f1162dfea4969bc17417563ac55d93b72e84c1e # 3.0.0
)

add_subdirectory(sfml)
