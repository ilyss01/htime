run:
	clang -o htime main.c && ./htime

install:
	clang -o htime main.c && 

format:
	clang-format --style=LLVM main.c
