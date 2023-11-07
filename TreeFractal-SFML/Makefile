.PHONY: clean

ifeq ($(OS), Windows_NT)
  EXECUTABLE = example.exe
else
  EXECUTABLE = example
endif
BINDIR = ../bin
OBJDIR = ../obj
SRCDIR = src
CXXSTANDARD = -std=c++17
WARNINGS = -Wall -Wextra -Werror -Wpedantic -pedantic-errors
ifeq ($(OS), Windows_NT)
  #INCLUDES = -D_WIN32 -DSFML_STATIC -I/mingw64/include
  INCLUDES = -D_WIN32 -I/mingw64/include
  LINK_DIRS = -L/mingw64/lib
  # These are only needed if linking statically
  #LIBRARIES_EXT = -lopengl32 -lwinmm -lgdi32 -lfreetype
  LIBRARIES_EXT =
else
  INCLUDES =
  LINK_DIRS =
  LIBRARIES_EXT =
endif
LIBRARIES = -lm -lsfml-graphics -lsfml-window -lsfml-system $(LIBRARIES_EXT)

$(BINDIR)/$(EXECUTABLE): $(OBJDIR)/main.o
	$(CXX) -o $@ $^ $(LINK_DIRS) $(LIBRARIES)

$(OBJDIR)/main.o: $(SRCDIR)/main.cxx $(OBJDIR) $(BINDIR)
	$(CXX) -c -o $@ $< $(INCLUDES) $(WARNINGS) $(CXXSTANDARD)

$(BINDIR):
	mkdir -p $@

$(OBJDIR):
	mkdir -p $@

clean:
	rm -rf $(BINDIR) $(OBJDIR)
