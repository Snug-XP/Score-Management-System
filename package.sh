#!/bin/sh
rm -rf build
mkdir build && cd build
cmake ..
cmake --build .
cpack
#ָ��ִ�к����û��������buildĿ¼������2��������Ҫ���ļ���һ����deb��װ����һ���ǿ�ִ���ļ�