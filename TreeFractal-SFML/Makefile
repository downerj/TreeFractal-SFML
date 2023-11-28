.PHONY: clean

EXECUTABLE = example
BINDIR = bin
OBJDIR = obj
SRCDIR = src
CCXXSTD = -std=c++20
CWARNS = -Wall -Wextra -Werror -Wpedantic -pedantic-errors
LLIBS = -lsfml-graphics -lsfml-window -lsfml-system -lm
DEBUGS =

MAIN_OBJ = $(OBJDIR)/main.o
MAIN_CXX = $(SRCDIR)/main.cxx
BRANCH_CXX = $(SRCDIR)/branch.cxx
BRANCH_HXX = $(SRCDIR)/branch.hxx
BRANCH_OBJ = $(OBJDIR)/branch.o
DRAW_CXX = $(SRCDIR)/draw.cxx
DRAW_HXX = $(SRCDIR)/draw.hxx
DRAW_OBJ = $(OBJDIR)/draw.o
DEBUG_HXX = $(SRCDIR)/debug.hxx
MATH_HXX = $(SRCDIR)/math.hxx
OPTIONS_CXX = $(SRCDIR)/options.cxx
OPTIONS_HXX = $(SRCDIR)/options.hxx
OPTIONS_OBJ = $(OBJDIR)/options.o
TREE_CXX = $(SRCDIR)/tree.cxx
TREE_HXX = $(SRCDIR)/tree.hxx
TREE_OBJ = $(OBJDIR)/tree.o

release: DEBUGS = -O3
release: $(BINDIR)/$(EXECUTABLE)

debug: DEBUGS = -DDEBUG -Og -g
debug: $(BINDIR)/$(EXECUTABLE)

$(BINDIR)/$(EXECUTABLE):  $(BRANCH_OBJ) $(DRAW_OBJ) $(MAIN_OBJ) $(OPTIONS_OBJ) $(TREE_OBJ)
	mkdir -p $(BINDIR)
	$(CXX) -o $@ $^ $(LLIBS)

$(MAIN_OBJ): $(MAIN_CXX) $(BRANCH_HXX) $(TREE_HXX) $(MATH_HXX) $(DEBUG_HXX)
	mkdir -p $(OBJDIR)
	$(CXX) -c -o $@ $< $(CWARNS) $(CCXXSTD) $(DEBUGS)

$(BRANCH_OBJ): $(BRANCH_CXX) $(BRANCH_HXX)
	mkdir -p $(OBJDIR)
	$(CXX) -c -o $@ $< $(CWARNS) $(CCXXSTD) $(DEBUGS)

$(DRAW_OBJ): $(DRAW_CXX) $(DRAW_HXX) $(BRANCH_HXX) $(TREE_HXX) $(MATH_HXX) $(DEBUG_HXX) $(OPTIONS_HXX)
	mkdir -p $(OBJDIR)
	$(CXX) -c -o $@ $< $(CWARNS) $(CCXXSTD) $(DEBUGS)

$(OPTIONS_OBJ): $(OPTIONS_CXX) $(OPTIONS_HXX)
	mkdir -p $(OBJDIR)
	$(CXX) -c -o $@ $< $(CWARNS) $(CCXXSTD) $(DEBUGS)

$(TREE_OBJ): $(TREE_CXX) $(TREE_HXX) $(BRANCH_HXX) $(MATH_HXX) $(DEBUG_HXX) $(OPTIONS_HXX)
	mkdir -p $(OBJDIR)
	$(CXX) -c -o $@ $< $(CWARNS) $(CCXXSTD) $(DEBUGS)

clean:
	rm -rf $(BINDIR) $(OBJDIR)
