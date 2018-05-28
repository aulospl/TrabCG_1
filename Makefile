all:
	@g++ -Wall -lglut -lGLU -lGL -lm -o trab trab2.cpp

clean:
	@rm trab

run:
	@./trab
