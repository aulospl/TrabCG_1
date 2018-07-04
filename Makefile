all:
	@g++ -Wall -lglut -lGLU -lGL -lm -o trab trab3.cpp

clean:
	@rm trab

run:
	@./trab

test: clean all run
	@echo "clean"
	@echo "all"
	@echo "run"
	
