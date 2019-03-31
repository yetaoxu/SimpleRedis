cmake_minimum_required(VERSION 3.12)
project(SimpleRedis)

set(CMAKE_CXX_STANDARD 14)

add_executable(SimpleRedis main.cpp DataNode.cpp LinkListNode.cpp HashTable.cpp)