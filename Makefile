# CC=g++
# CFLAGS=-I -Wall -g
# #SRCS=Matrix4x4.cpp
# DEPS=Matrix4x4.h

# %.0: %.cpp $(DEPS)
# 	$(CC) -c -o $@ $< $(CGLAGS)

# all:
# 	$(CC) $(CGLAGS) main.cpp Matrix4x4.cpp -o main $(CGLAGS) 

all:
	g++ test.cpp Matrix4x4.cpp -o test