all:
	@g++ -Wall -lglut -lGLU -lGL -lm -o trab trab1.cpp

clean:
	@rm trab

run:
	@./trab
