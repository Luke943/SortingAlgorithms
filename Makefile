sorting: sorting.c
	gcc -o sorttest sorttest.c sorting.c
	gcc -o speedtest speedtest.c sorting.c
	gcc -o searchtest searchtest.c sorting.c

sorttest: sorttest.c
	gcc -o sorttest sorttest.c sorting.c
	
speedtest: speedtest.c
	gcc -o speedtest speedtest.c sorting.c

searchtest: searchtest.c
	gcc -o searchtest searchtest.c sorting.c
