CC = g++
OPT = -O2

all : ppm2jack

ppm2jack : ppm2jack.cpp
	$(CC) $(OPT) ppm2jack.cpp -o ppm2jack
		
clean: 
	rm ppm2jack ppm2jack.o

