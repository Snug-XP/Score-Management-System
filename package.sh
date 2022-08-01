#!/bin/sh
rm -rf build
mkdir build && cd build
cmake ..
cmake --build .
cpack
#指令执行后如果没报错，会在build目录下生成2个我们需要的文件，一个是deb安装包，一个是可执行文件