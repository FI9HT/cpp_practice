cmake_minimum_required(VERSION 2.8)

project(PRACTICE)

set(CMAKE_CXX_STANDARD 98)
add_compile_options(-g -Wall -O0)

set(ALGORITHM_SRC
    ${PROJECT_SOURCE_DIR}/algorithm/sort.cpp
)

set(DATASTRUCTURE_TREE_SRC
    ${PROJECT_SOURCE_DIR}/data_structure/tree/binary_tree.cpp
)

set(ROOT_SRC
    ${PROJECT_SOURCE_DIR}/main.cpp
)

# include_directories()
# link_directories()

add_executable(test ${ALGORITHM_SRC} ${DATASTRUCTURE_TREE_SRC} ${ROOT_SRC})

# target_link_directories(MAIN ...)
