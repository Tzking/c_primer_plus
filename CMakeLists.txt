project(demo CXX)

# 设置目录
set(SRC_DIR "ch13")
add_executable(${PROJECT_NAME} 
    ${SRC_DIR}/usedma.cpp 
    ${SRC_DIR}/dma.hpp
    ${SRC_DIR}/dma.cpp )