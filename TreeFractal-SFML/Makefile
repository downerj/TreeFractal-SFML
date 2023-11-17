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
BRANCH_CXX = $(SRCDIR)/branch.cxx
BRANCH_HXX = $(SRCDIR)/branch.hxx
BRANCH_OBJ = $(OBJDIR)/branch.o
CONDITIONS_CXX = $(SRCDIR)/conditions.cxx
CONDITIONS_HXX = $(SRCDIR)/conditions.hxx
CONDITIONS_OBJ = $(OBJDIR)/conditions.o
DRAW_CXX = $(SRCDIR)/draw.cxx
DRAW_HXX = $(SRCDIR)/draw.hxx
DRAW_OBJ = $(SRCDIR)/draw.obj
MATH_HXX = $(SRCDIR)/math.hxx

$(BINDIR)/$(EXECUTABLE): $(MAIN_OBJ) $(BRANCH_OBJ) $(CONDITIONS_OBJ) $(DRAW_OBJ)
	mkdir -p $(BINDIR)
	$(CXX) -o $@ $^ $(LLIBS)

$(MAIN_OBJ): $(MAIN_CXX) $(BRANCH_HXX) $(CONDITIONS_HXX) $(MATH_HXX)
	mkdir -p $(OBJDIR)
	$(CXX) -c -o $@ $< $(CWARNS) $(CCXXSTD)

$(BRANCH_OBJ): $(BRANCH_CXX) $(BRANCH_HXX) $(CONDITIONS_HXX) $(MATH_HXX)
	$(CXX) -c -o $@ $< $(CWARNS) $(CCXXSTD)

$(CONDITIONS_OBJ): $(CONDITIONS_CXX) $(CONDITIONS_HXX) $(MATH_HXX)
	$(CXX) -c -o $@ $< $(CWARNS) $(CCXXSTD)

$(DRAW_OBJ): $(DRAW_CXX) $(DRAW_HXX) $(BRANCH_HXX) $(CONDITIONS_HXX) $(MATH_HXX)
	$(CXX) -c -o $@ $< $(CWARNS) $(CCXXSTD)

clean:
	rm -rf $(BINDIR) $(OBJDIR)
