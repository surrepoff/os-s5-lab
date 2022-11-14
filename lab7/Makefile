all:
	gcc -c -fPIC -Wall lib/list_functions.c -o lib/list_functions.o
	gcc -shared lib/*.o -o liblist_functions.so
	gcc -c main.c
	gcc main.o -L. -llist_functions -o main
	rm main.o
	rm lib/list_functions.o
	./main

clean:
	rm main
	rm liblist_functions.so

#export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:usr/unfeel/os/lab07/
#ps aux | grep ./main
#cat /proc/ID/maps