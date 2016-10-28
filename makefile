list: stat.c
	gcc stat.c -o stat

run: stat
	./stat

clean:
	rm *~
	rm stat
