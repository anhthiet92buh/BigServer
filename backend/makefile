all: blmain blclient ustring
# g++ -I "/usr/local/include" -L "/usr/local/lib" BLmain.cpp -licui18n -licuuc -licudata -lpq -o blmain
blmain: BLmain.cpp
	clang++  -std=c++11  -I/usr/local/include   -c BLmain.cpp -o blmain.o
	clang++  -std=c++11  -I/usr/local/include  blmain.o  -L/usr/local/lib -licui18n -licuuc -licudata -lpq     -o blmain  -licui18n -licuuc
blclient: BLclient.cpp
	g++ BLclient.cpp -lpq -o blclient
ustring: ustring.cpp
	clang++  -std=c++11  -I/usr/local/include   -c ustring.cpp -o ustring.o
	clang++  -std=c++11  -I/usr/local/include  ustring.o  -L/usr/local/lib -licui18n -licuuc -licudata      -o ustring  -licui18n -licuuc
clean:
	rm -rf blmain blclient ustring *.o