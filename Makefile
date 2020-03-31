.PHONY: clean

all: build stream 

stream: main_client_stream main_server_stream

main_client_stream: main_client_stream.o sock_functions.o
	gcc -g build/main_client_stream.o build/sock_functions.o -o client_stream

main_server_stream: main_server_stream.o sock_functions.o
	gcc -g build/main_server_stream.o build/sock_functions.o -o server_stream

sock_functions.o: src/sock_functions.c src/sock_functions.h
	gcc -g -c src/sock_functions.c -o build/sock_functions.o

main_client_stream.o: src/main_client_stream.c src/sock_functions.h
	gcc -g -c src/main_client_stream.c -o build/main_client_stream.o

main_server_stream.o: src/main_server_stream.c src/sock_functions.h
	gcc -g -c src/main_server_stream.c -o build/main_server_stream.o
	
build:
	mkdir build

clean:
	rm -rf build client_stream server_stream
