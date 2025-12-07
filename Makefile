.PHONY: build
build: src/main.cpp 
	clang++ -std=c++20 -o main ./src/main.cpp

.PHONY: llvm
llvm: ./src/main.cpp
	clang++ -S -emit-llvm ./src/main.cpp
