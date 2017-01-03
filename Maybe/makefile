# DIR_INC = include
# DIR_SRC = src
# DIR_OBJ = obj
# DIR_BIN = bin

# SRC = $(wildcard ${DIR_SRC}/*.cpp)$(wildcard *.cpp)
# OBJ = $(patsubst %.cpp,${DIR_OBJ}/%.o,$(notdir ${SRC}))$(patsubst %.cpp,${DIR_OBJ}/%.o,$(notdir /)) 

# TARGET = main

# BIN_TARGET = ${DIR_BIN}/${TARGET}

# CC = clang++
# CFLAGS = -std=c++11 -Wall -Wno-c++11-extensions -I${DIR_INC} ${DIR_INC}/algorithm

# ${BIN_TARGET}:${OBJ}
#     $(CC) $(OBJ)  -o $@
    
# ${DIR_OBJ}/%.o:${DIR_SRC}/%.cpp /%.cpp
#     $(CC) $(CFLAGS) -c  $< -o $@
# .PHONY:clean
# clean:
#     find ${DIR_OBJ} -name *.o -exec rm -rf {}