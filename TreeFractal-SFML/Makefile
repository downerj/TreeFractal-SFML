.PHONY: clean

EXECUTABLE = example
BINDIR = bin
OBJDIR = obj
SRCDIR = src
CCXXSTD = -std=c++17
CWARNS = -Wall -Wextra -Werror -Wpedantic -pedantic-errors
LLIBS = -lsfml-graphics -lsfml-window -lsfml-system

$(BINDIR)/$(EXECUTABLE): $(OBJDIR)/main.o
	mkdir -p $(BINDIR)
	$(CXX) -o $@ $^ $(LLIBS)

$(OBJDIR)/main.o: $(SRCDIR)/main.cxx
	mkdir -p $(OBJDIR)
	$(CXX) -c -o $@ $< $(CWARNS) $(CCXXSTD)

clean:
	rm -rf $(BINDIR) $(OBJDIR)
