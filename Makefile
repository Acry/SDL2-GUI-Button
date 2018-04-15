CFLAGS   = -Wall -Wextra -mtune=native `sdl2-config --cflags`
LDFLAGS  = `sdl2-config --libs` -lSDL2_image -lSDL2_ttf

debug:helper.c main.c
	$(CC) $(CFLAGS) -g $? -o button $(LDFLAGS)
stable:helper.c main.c
	$(CC) $(CFLAGS) $? -o button $(LDFLAGS)
clean:
	rm -vfr *~ button
