message(STATUS "Fetching SFML 2.6.1 from https://github.com/SFML/SFML | TAG: 69ea0cd863aed1d4092b970b676924a716ff718b ...")

# No need to build network modules
set(SFML_BUILD_NETWORK FALSE)

FetchContent_MakeAvailable(sfml)
