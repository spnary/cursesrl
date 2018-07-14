cursesrl: object.o cursesrl.o map.o rlconst.o drawing.o character.o utility.o
	clang -g object.o map.o cursesrl.o rlconst.o drawing.o character.o utility.o -lncurses -o cursesrl
object.o: object.h object.c
	clang -c -g object.c 
map.o: map.h map.c rlconst.h
	clang -c -g map.c
cursesrl.o: object.h cursesrl.c map.h rlconst.h drawing.h
	clang -c -g cursesrl.c
rlconst.o: rlconst.h rlconst.c
	clang -c -g rlconst.c	
drawing.o: drawing.h drawing.c rlconst.h map.h
	clang -c -g drawing.c
character.o: character.h character.c
	clang -c -g character.c
utility.o: utility.h utility.c
	clang -c -g utility.c

utility_tests.o: utility.h utility_tests.c
	clang -c -g `pkg-config --cflags glib-2.0`  utility_tests.c 
tests: utility_tests.o
	clang -g utility_tests.o utility.o `pkg-config --libs glib-2.0` -o tests
