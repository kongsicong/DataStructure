
CMAKE_MINIMUM_REQUIRED(VERSION 3.0)



FILE(GLOB SRC *.cpp)
FILE(GLOB INC *.h *.hpp)

ADD_LIBRARY(array ${SRC} ${INC})