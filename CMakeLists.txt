cmake_minimum_required(VERSION 3.15)
# 工程名
project(ODP)
# 生成compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS  ON)
# 递归添加所有c文件
file(GLOB_RECURSE PROJECT_SRC *.c *.cpp *.h)
add_definitions(-DUNICODE)
# 生成可执行文件
add_executable(ODP ${PROJECT_SRC})
# 拷贝compile_commands.json到根目录
# execute_process(COMMAND ${CMAKE_COMMAND} -E
# copy "${CMAKE_CURRENT_LIST_DIR}/build/compile_commands.json"  "${CMAKE_CURRENT_LIST_DIR}/"
# )