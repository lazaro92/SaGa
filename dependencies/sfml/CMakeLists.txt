message(STATUS "Fetching SFML 3.0.0 from https://github.com/SFML/SFML | TAG: 7f1162dfea4969bc17417563ac55d93b72e84c1e ...")

# No need to build network modules
set(SFML_BUILD_NETWORK FALSE)

FetchContent_MakeAvailable(sfml)
