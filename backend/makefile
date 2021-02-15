all: blmain blclient

blmain: BLmain.cpp
	g++ BLmain.cpp -lpq -o blmain
blclient: BLclient.cpp
	g++ BLclient.cpp -lpq -o blclient
clean:
	rm -rf blmain blclient *.o