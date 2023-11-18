.PHONY: clean

EXECUTABLE = example
BINDIR = bin
OBJDIR = obj
SRCDIR = src
CCXXSTD = -std=c++17
CWARNS = -Wall -Wextra -Werror -Wpedantic -pedantic-errors
LLIBS = -lsfml-graphics -lsfml-window -lsfml-system -lm

MAIN_OBJ = $(OBJDIR)/main.o
MAIN_CXX = $(SRCDIR)/main.cxx
BRANCH_HXX = $(SRCDIR)/branch.hxx
TREE_CXX = $(SRCDIR)/tree.cxx
TREE_HXX = $(SRCDIR)/tree.hxx
TREE_OBJ = $(OBJDIR)/tree.o
DRAW_CXX = $(SRCDIR)/draw.cxx
DRAW_HXX = $(SRCDIR)/draw.hxx
DRAW_OBJ = $(OBJDIR)/draw.o
MATH_HXX = $(SRCDIR)/math.hxx

$(BINDIR)/$(EXECUTABLE): $(MAIN_OBJ) $(TREE_OBJ) $(DRAW_OBJ)
	mkdir -p $(BINDIR)
	$(CXX) -o $@ $^ $(LLIBS)

$(MAIN_OBJ): $(MAIN_CXX) $(BRANCH_HXX) $(TREE_HXX) $(MATH_HXX)
	mkdir -p $(OBJDIR)
	$(CXX) -c -o $@ $< $(CWARNS) $(CCXXSTD)

$(TREE_OBJ): $(TREE_CXX) $(TREE_HXX) $(MATH_HXX)
	$(CXX) -c -o $@ $< $(CWARNS) $(CCXXSTD)

$(DRAW_OBJ): $(DRAW_CXX) $(DRAW_HXX) $(BRANCH_HXX) $(TREE_HXX) $(MATH_HXX)
	$(CXX) -c -o $@ $< $(CWARNS) $(CCXXSTD)

clean:
	rm -rf $(BINDIR) $(OBJDIR)
