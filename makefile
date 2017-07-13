cursesrl: object.o cursesrl.o map.o rlconst.o
	clang -g object.o map.o cursesrl.o rlconst.o -lncurses -o cursesrl
object.o: object.h object.c
	clang -c -g object.c 
map.o: map.h map.c rlconst.h
	clang -c -g map.c
cursesrl.o: object.h cursesrl.c map.h rlconst.h
	clang -c -g cursesrl.c
rlconst.o: rlconst.h rlconst.c
	clang -c -g rlconst.c	
