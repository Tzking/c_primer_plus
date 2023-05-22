project(demo CXX)

# 设置目录
set(SRC_DIR "ch14")
add_executable(${PROJECT_NAME} 
    ${SRC_DIR}/usestuc.cpp 
    ${SRC_DIR}/student.hpp
    ${SRC_DIR}/student.cpp )