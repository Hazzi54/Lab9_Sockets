.PHONY: clean

all: build stream dgram

stream: main_client_stream main_server_stream

dgram: main_client_dgram main_server_dgram

main_client_stream: main_client_stream.o sock_functions.o
	gcc -g build/main_client_stream.o build/sock_functions.o -o client_stream

main_server_stream: main_server_stream.o sock_functions.o
	gcc -g build/main_server_stream.o build/sock_functions.o -o server_stream

main_client_dgram: main_client_dgram.o sock_functions.o
	gcc -g build/main_client_dgram.o build/sock_functions.o -o client_dgram

main_server_dgram: main_server_dgram.o sock_functions.o
	gcc -g build/main_server_dgram.o build/sock_functions.o -o server_dgram

sock_functions.o: src/sock_functions.c src/sock_functions.h
	gcc -g -c src/sock_functions.c -o build/sock_functions.o

main_client_stream.o: src/main_client_stream.c src/sock_functions.h
	gcc -g -c src/main_client_stream.c -o build/main_client_stream.o

main_server_stream.o: src/main_server_stream.c src/sock_functions.h
	gcc -g -c src/main_server_stream.c -o build/main_server_stream.o

main_client_dgram.o: src/main_client_dgram.c src/sock_functions.h
	gcc -g -c src/main_client_dgram.c -o build/main_client_dgram.o

main_server_dgram.o: src/main_server_dgram.c src/sock_functions.h
	gcc -g -c src/main_server_dgram.c -o build/main_server_dgram.o
	
build:
	mkdir build

clean:
	rm -rf build client_stream server_stream client_dgram server_dgram
