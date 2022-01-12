getMidiNote.o: getMidiNote.c
	clang -c getMidiNote.c

notecalc.o: notecalc.c functions.h
	clang -c notecalc.c

notecalc: notecalc.o getMidiNote.o
	clang notecalc.o getMidiNote.o -o notecalc