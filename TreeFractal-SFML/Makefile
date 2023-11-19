.PHONY: clean

EXECUTABLE = example
BINDIR = bin
OBJDIR = obj
SRCDIR = src
CCXXSTD = -std=c++17
CWARNS = -Wall -Wextra -Werror -Wpedantic -pedantic-errors
LLIBS = -lsfml-graphics -lsfml-window -lsfml-system -lm
DEBUGS =

MAIN_OBJ = $(OBJDIR)/main.o
MAIN_CXX = $(SRCDIR)/main.cxx
BRANCH_HXX = $(SRCDIR)/branch.hxx
DRAW_CXX = $(SRCDIR)/draw.cxx
DRAW_HXX = $(SRCDIR)/draw.hxx
DRAW_OBJ = $(OBJDIR)/draw.o
MATH_HXX = $(SRCDIR)/math.hxx
TREE_CXX = $(SRCDIR)/tree.cxx
TREE_HXX = $(SRCDIR)/tree.hxx
TREE_OBJ = $(OBJDIR)/tree.o
DEBUG_HXX = $(SRCDIR)/debug.hxx

release: DEBUGS = -O3
release: $(BINDIR)/$(EXECUTABLE)

debug: DEBUGS = -DDEBUG -Og -g
debug: $(BINDIR)/$(EXECUTABLE)

$(BINDIR)/$(EXECUTABLE): $(MAIN_OBJ) $(TREE_OBJ) $(DRAW_OBJ)
	mkdir -p $(BINDIR)
	$(CXX) -o $@ $^ $(LLIBS)

$(MAIN_OBJ): $(MAIN_CXX) $(BRANCH_HXX) $(TREE_HXX) $(MATH_HXX) $(DEBUG_HXX)
	mkdir -p $(OBJDIR)
	$(CXX) -c -o $@ $< $(CWARNS) $(CCXXSTD) $(DEBUGS)

$(TREE_OBJ): $(TREE_CXX) $(TREE_HXX) $(MATH_HXX) $(DEBUG_HXX)
	$(CXX) -c -o $@ $< $(CWARNS) $(CCXXSTD) $(DEBUGS)

$(DRAW_OBJ): $(DRAW_CXX) $(DRAW_HXX) $(BRANCH_HXX) $(TREE_HXX) $(MATH_HXX) $(DEBUG_HXX)
	$(CXX) -c -o $@ $< $(CWARNS) $(CCXXSTD) $(DEBUGS)

clean:
	rm -rf $(BINDIR) $(OBJDIR)
