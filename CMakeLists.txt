project(scoreapp)
cmake_minimum_required(VERSION 2.8.12.2)
set(CMAKE_CXX_STANDARD 11)

# 加入所有头文件
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
# 添加所有源文件
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRCLIST)
# 将源文件打包成静态态库
add_library(libcircle STATIC ${SRCLIST})

add_executable(scoreapp sample/main.cpp)

# 将动态库链接到目标
target_link_libraries(scoreapp libcircle)


install(TARGETS scoreapp
    COMPONENT linapp
    RUNTIME DESTINATION "/"
    LIBRARY DESTINATION "/"
    DESTINATION "/"
)
#我们使用install()命令告诉CMake在安装时要做什么。我们告诉命令我们要用于安装程序的目标（“ scoreapp”）。
#我们还告诉目标位置我们想要安装的位置，在这种情况下，它是“ /”目录。
#RUNTIME和LIBRARY目标指定了在我们有其他库的情况下希望放置库的目标。

SET(CPACK_GENERATOR "DEB")
SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "KK") #required
INCLUDE(CPack)
# CPack是CMake使用的打包工具。