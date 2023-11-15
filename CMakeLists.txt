cmake_minimum_required(VERSION 2.8)

project(PRACTICE)

set(CMAKE_CXX_STANDARD 11)
add_compile_options(-g -Wall -O0)

set(DIR_ALGORITHM_SRC_FILE
    ${PROJECT_SOURCE_DIR}/algorithm/sort.cpp
)
set(DIR_ROOT_SRC_FILE
    ${PROJECT_SOURCE_DIR}/main.cpp
)

# include_directories()
# link_directories()

add_executable(MAIN ${DIR_ALGORITHM_SRC_FILE} ${DIR_ROOT_SRC_FILE})

# target_link_directories(MAIN ...)
