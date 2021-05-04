all:
	gcc   menuuu.c pres.c  new.c entite.c -o prog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lm; ./prog
