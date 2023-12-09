cmake_minimum_required(VERSION 3.27)
project(termclock)

set(CMAKE_CXX_STANDARD 23)

add_executable(termclock main.cc
	digits.hh)
