#! /bin/bash
echo "begin..."
rm -rf /root/Desktop/cpp_stl/
cd ..
cp -r cpp_stl/ /root/Desktop/
cd /root/Desktop/cpp_stl/
mkdir main
cp -r inc/ main/
cp -r src/ main/
cp BUILD main/
cp test.cpp main/
bazel clean
bazel build //main:cpp_stl
echo "end..."










