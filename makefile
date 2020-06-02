CC = g++
CFLAGS = -c
LIBS = -lSDL2main -lSDL2 -lSDL2_gfx
DEPS = game_manager.h vec2.h boid.h
OBJ = game_manager.o vec2.o boid.o teste.o
EXEC = ./teste


%.o: %.cpp $(DEPS)
		$(CC) $(CFLAGS) -o $@ $<

teste: $(OBJ)
		$(CC) -o $@ $^ $(LIBS)

run: teste
		$(EXEC)

clean:
		rm -rf *.o teste
