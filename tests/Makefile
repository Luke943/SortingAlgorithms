all: sort speed search

sort: sorting.o
	gcc -o sorttest sorttest.c sorting.o
	
speed: sorting.o
	gcc -o speedtest speedtest.c sorting.o

search: sorting.o
	gcc -o searchtest searchtest.c sorting.o

sorting.o: ../sorting.c
	gcc -c ../sorting.c

clean:
ifneq ($(wildcard *.o), )
	rm *.o
endif
ifneq ($(wildcard *.exe), )
	rm *.exe
endif