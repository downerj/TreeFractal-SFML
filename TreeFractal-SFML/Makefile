.PHONY: clean

EXECUTABLE = example
BINDIR = bin
OBJDIR = obj
SRCDIR = src
CCXXSTD = -std=c++17
CWARNS = -Wall -Wextra -Werror -Wpedantic -pedantic-errors
LLIBS = -lsfml-graphics -lsfml-window -lsfml-system

$(BINDIR)/$(EXECUTABLE): $(OBJDIR)/main.o
	$(CXX) -o $@ $^ $(LLIBS)

$(OBJDIR)/main.o: $(SRCDIR)/main.cxx $(OBJDIR) $(BINDIR)
	$(CXX) -c -o $@ $< $(CWARNS) $(CCXXSTD)

$(BINDIR):
	mkdir -p $@

$(OBJDIR):
	mkdir -p $@

clean:
	rm -rf $(BINDIR) $(OBJDIR)
