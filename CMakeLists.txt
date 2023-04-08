cmake_minimum_required(VERSION 3.24)
project(ProcesorCSS)

set(CMAKE_CXX_STANDARD 17)

add_executable(ProcesorCSS main.cpp String.cpp String.h Item.h List.h Processor.cpp Processor.h Selector.cpp Selector.h Attribute.cpp Attribute.h BlockOfCSS.cpp BlockOfCSS.h)
