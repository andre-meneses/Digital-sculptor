# Name of the project
PROJ_NAME=sculptor
 
# .c files
C_SOURCE=$(wildcard ./src/*.cpp)
 
# .h files
H_SOURCE=$(wildcard ./include/*.hpp)
 
# Object files
OBJ=$(subst .cpp,.o,$(subst source,objects,$(C_SOURCE)))
 
# Compiler and linker
CC=g++
 
# Flags for compiler
CC_FLAGS=-c         \
         -W         \
         -Wall      \
         -pedantic
 
# Command used at clean target
RM = rm -rf
 
#
# Compilation and linking
#
all: objFolder $(PROJ_NAME)
 
$(PROJ_NAME): $(OBJ)
	@ echo 'Building binary using G++ linker: $@'
	$(CC) $^ -o $@
	@ echo 'Finished building binary: $@'
	@ echo ' '
 
./objects/%.o: ./src/%.cpp ./include/%.hpp
	@ echo 'Building target using G++ compiler: $<'
	$(CC) $< $(CC_FLAGS) -o $@
	@ echo ' '
 
./objects/main.o: ./src/main.cpp $(H_SOURCE)
	@ echo 'Building target using G++ compiler: $<'
	$(CC) $< $(CC_FLAGS) -o $@
	@ echo ' '
 
objFolder:
	@ mkdir -p objects
 
clean:
	@ $(RM) ./objects/*.o $(PROJ_NAME) *~
	@ rmdir objects
 
.PHONY: all clean
