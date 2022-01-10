CC=g++
DEPS=
# SOURCES=functions.cpp main.cpp
SRCDIR=src
OBJDIR=obj
OBJECTS=hello_make.o
OBJ=$(patsubst %, $(OBJDIR)/%, $(OBJECTS))
EXECUTABLE=hello_make
CFLAGS=
LIBS=
# aggiungere LDFLAGS?

# compile
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) -c -o $@ $<

# link
$(EXECUTABLE): $(OBJ) $(DEPS)
	$(CC) -o $@ $^

# clean
.PHONY: clean
clean: 
	rm -rf $(OBJDIR)/*.o
