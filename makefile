main:main.o
	g++ main.o -o main
main.o:main.s	
	g++ -c main.s -o main.o
main.s:main.i
	g++ -S main.i -o main.s
main.i:main.cc
	gcc -E main.cc -o main.i

.PHONY:clean
clean:
	rm -rf main.o main.s main.i