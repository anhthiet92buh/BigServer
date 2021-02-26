all: blmain blclient

blmain: BLmain.cpp
	g++ -I "/usr/local/include" -L "/usr/local/lib" BLmain.cpp -licui18n -licuuc -licudata -lpq -o blmain -licui18n -licuuc
blclient: BLclient.cpp
	g++ -BLclient.cpp -lpq -o blclient
clean:
	rm -rf blmain blclient *.o