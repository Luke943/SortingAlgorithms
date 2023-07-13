all: sorting.c sorttest.c speedtest.c searchtest.c
	gcc -o sorttest sorttest.c sorting.c
	gcc -o speedtest speedtest.c sorting.c
	gcc -o searchtest searchtest.c sorting.c

sort: sorttest.c sorting.c
	gcc -o sorttest sorttest.c sorting.c
	
speed: speedtest.c sorting.c
	gcc -o speedtest speedtest.c sorting.c

search: searchtest.c sorting.c
	gcc -o searchtest searchtest.c sorting.c
