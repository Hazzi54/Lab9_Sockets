.PHONY: clean

all: build main_client main_server

main_client: main_client.o sock_functions.o
	gcc -g build/main_client.o build/sock_functions.o -o client

main_server: main_server.o sock_functions.o
	gcc -g build/main_server.o build/sock_functions.o -o server

sock_functions.o: src/sock_functions.c src/sock_functions.h
	gcc -g -c src/sock_functions.c -o build/sock_functions.o

main_client.o: src/main_client.c src/sock_functions.h
	gcc -g -c src/main_client.c -o build/main_client.o

main_server.o: src/main_server.c src/sock_functions.h
	gcc -g -c src/main_server.c -o build/main_server.o
	
build:
	mkdir build

clean:
	rm -rf build client server
