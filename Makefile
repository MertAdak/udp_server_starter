udp_client: main.o udp_server.o
	g++ main.o udp_server.o -o udp_server -lSDL2

main.o: src/main.cpp
	g++ -c src/main.cpp

udp_server.o: src/udp_server.cpp src/udp_server.h
	g++ -c src/udp_server.cpp

clean: 
	rm *.o udp_server