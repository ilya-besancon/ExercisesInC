trouty: trout.h trout.c
	gcc -c trout.c -o trouty

utily: util.c util.h
	gcc -c util.c -o utily

mainy: main.c trouty utily
	gcc -c main.c -o mainy

trout: mainy
	gcc -g -Wall mainy utily trouty -o trout
