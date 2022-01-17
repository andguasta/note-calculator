%.o: %.c
	clang -g -c $<

notecalc: notecalc.o conversions.o
	clang -g notecalc.o conversions.o -o notecalc

clean:
	rm notecalc;
	rm *.o; 