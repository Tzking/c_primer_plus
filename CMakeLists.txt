project(demo CXX)

# 设置目录
set(SRC_DIR "ch14")
add_executable(${PROJECT_NAME} 
    ${SRC_DIR}/worktest.cpp 
    ${SRC_DIR}/worker.hpp
    ${SRC_DIR}/worker.cpp )