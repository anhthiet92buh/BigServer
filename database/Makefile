allTest: testlibpq

testlibpq: testlibpq.c
	gcc -Wall -Wextra -I "./usr/include/postgresql/" -L "/usr/lib/postgresql/13/lib" testlibpq.c -lpq -o postgresql
clean:
	rm -rf *.o *.out postgresql