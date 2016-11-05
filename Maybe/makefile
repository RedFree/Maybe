#设置 ".cpp" 文件路径， 下面包含了 “../src“,  ”/“ 两个路径
vpath %.cpp maybe src/obj test

#指定包含文件路径 下面为包含 "../include" 路径
vpath %.h include include/algorithm include/obj
#vpath % bin
#because the gnu version is too old, so 
#i have to use clang++ complier to support c++ 11
CC = clang++

#*.o 通配中间文件".o"
objects = *.o #WVector.o
TARGET = bin/demo
$(TARGET): $(objects)
	$(CC) -o $(TARGET) $(objects)

#通配源文件 ".cpp"文件
$(objects): *.cpp #WVector.cpp

clean:
	rm $(TARGET) $(objects)

