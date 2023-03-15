cmake_minimum_required(VERSION 3.23)
project(compiler)

set(CMAKE_CXX_STANDARD 20)

add_executable(compiler main.cpp Lexer.cpp Lexer.h Parser.cpp Parser.h CodeGen.cpp CodeGen.h AstNode.cpp AstNode.h Print.cpp Print.h driver.c)
