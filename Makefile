# Maxime Brodat
# maxime.brodat@utbm.fr
# maxime.brodat@fouss.fr
#
# Stéphane Perrez
# stéphane.perrez@utbm.fr
#
# Deadline of the project: 01/05/2015


# My general makefile template
CXX = gcc
CFLAGS = -Wall -Werror -g -ansi -pedantic -fpic
LIBSDIR = -L. -L/usr/lib
INCLUDEDIR = -I. -I/usr/include

# Library-related macros
ALIBTARGET2 = Polygon
ALIBTARGET = libPolygon.so
ALIBSOURCE = polygon
ALIBSOURCECFILE = $(ALIBSOURCE:=.c)
ALIBSOURCEOFILE = $(ALIBSOURCE:=.o)

BLIBTARGET2 = Utils
BLIBTARGET = libUtils.so
BLIBSOURCE = useful_fcts
BLIBSOURCECFILE = $(BLIBSOURCE:=.c)
BLIBSOURCEOFILE = $(BLIBSOURCE:=.o)

# Application-related macros
TARGET = polygonManager.exe
EXESOURCE = polygonmain
EXESOURCECFILE = $(EXESOURCE:=.c)
EXESOURCEOFILE = $(EXESOURCE:=.o)

# To overload the content of the LD_LIBRARY_PATH
# Export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:.

# Running the program
run: $(TARGET)
	@echo "\n Executing the executable " $(TARGET)
	./$(TARGET)

# Running the program using "valgrind" to check the memory usage
memory: $(TARGET)
	@echo "\n Executing the executable and checking the memory usage of " $(TARGET)
	valgrind -v ./$(TARGET)

# Running the program using "gdb" to debug the program
debug: $(TARGET)
	@echo "\n Executing the executable " $(TARGET) " and debuging it"
	gdb ./$(TARGET)

# Generating the executable
$(TARGET): $(EXESOURCEOFILE) $(ALIBTARGET) $(BLIBTARGET)
	@echo "\n Generating the executable " $@
	$(CXX) $(EXESOURCEOFILE) -l$(ALIBTARGET2) -l$(BLIBTARGET2) $(LIBSDIR) -o $(TARGET)

# Generating the library binary code
$(ALIBTARGET): $(ALIBSOURCEOFILE)
	@echo "\n Generating the library " $@
	$(CXX) $(CFLAGS) -shared $(ALIBSOURCEOFILE) -o $(ALIBTARGET)

$(BLIBTARGET): $(BLIBSOURCEOFILE)
	@echo "\n Generating the library " $@
	$(CXX) $(CFLAGS) -shared $(BLIBSOURCEOFILE) -o $(BLIBTARGET)

# Generating an object file from a C file having the same name
.c.o:
	@echo "\n Generating " $@ " from " $<
	$(CXX) $(CFLAGS) $(INCLUDEDIR) -c -o $@ $<

# Cleaning the content of the current directory
clean:
	@echo "\n Cleaning temporary files"
	rm -rf *.o *~ *.so *.exe
