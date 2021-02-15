all: client server sampleSever sampleClient severbogo clientbogo

client: client.cpp
	g++ client.cpp -o client
server: server.cpp
	g++ server.cpp -o server
sampleSever: sampleSever.cpp
	g++ sampleSever.cpp -o spSv
sampleClient: sampleClient.cpp
	g++ sampleClient.cpp -o spCli
severbogo: severBogo.cpp
	g++ severBogo.cpp -o severbogo
clientbogo: clientBogo.cpp
	g++ clientBogo.cpp -o clientbogo
clean:
	rm -rf *.o *.out client server spSv spCli severbogo clientbogo