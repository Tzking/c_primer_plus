project(demo CXX)

# 设置目录
set(SRC_DIR "ch13")
add_executable(${PROJECT_NAME} 
    ${SRC_DIR}/usebrass.cpp 
    ${SRC_DIR}/brass.hpp
    ${SRC_DIR}/brass.cpp )