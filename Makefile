define colorecho
      @tput setaf 2
      @echo $1
      @tput sgr0
endef

CFLAGS   = -Wall -Wextra -mtune=native -no-pie `sdl2-config --cflags`
LDFLAGS  = `sdl2-config --libs` -lSDL2_image -lSDL2_ttf

TARGETS     = button

.PHONY: all
all: $(TARGETS)

button: helper.c button.c
	@cc $(CFLAGS) -o $@ $+ $(LDFLAGS)
	$(call colorecho,"$@ success. ./\"$@\" to execute.")

.PHONY: clean
clean:
	@cd rm $(TARGETS) 2>/dev/null || true

# hot compile
# while inotifywait -e close_write ./code.c; do date +%X; make > /dev/null; done

#$<	first dependency
#$@	target name
#$+	list of all dependencies
#$^	list of all unique dependencies

