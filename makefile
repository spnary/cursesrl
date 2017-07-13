cursesrl: object.o cursesrl.o map.o
	clang -g object.o map.o cursesrl.o -lncurses -o cursesrl
object.o: object.h object.c
	clang -c -g object.c 
map.o: map.h map.c
	clang -c -g map.c
cursesrl.o: object.h cursesrl.c map.h
	clang -c -g cursesrl.c 
