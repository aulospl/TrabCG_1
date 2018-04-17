all:
	@g++ -o trabalho trabalho.cpp -lglut -lGLU -lGL -Wall -lm

run:
	@./trabalho

clean:
	@rm trabalho

zip:
	@zip -r testeT1CG trabalho.cpp Makefile
