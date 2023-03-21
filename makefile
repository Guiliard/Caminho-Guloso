# Nome do projeto
PROJ_NAME=Matriz
#wildcard vai pegar todos os arquivos cpp
CPP_SOURCE=$(wildcard ./*.cpp)

#wildcard vai pegar todos os arquivos hpp
HPP_SOURCE=$(wildcard ./*.hpp)

#Arquivos compilados
OBJ=$(subst .cpp,.o,$(subst source,objects,$(CPP_SOURCE)))

# Compiler and linker
CC=g++

# Flags para o compilador
# C: Compila mas não chama o linker
# Wall: mostra todos os warnings
# Wextra:  Warnings que o wall não mostra
# ansi: Só roda c++ padrão.  
# pedantic: Rejeita c++ não padrão
CC_FLAGS=-c         \
	 -Wextra    \
         -Wall      \
         -ansi      \
         -pedantic

# Command used at clean target
RM = rm -rf


# Compilation and linking

all: $(PROJ_NAME)

$(PROJ_NAME): $(OBJ)
	@ echo 'Building binary using G++ linker: $@'
	$(CC) $^ -o $@
	@ echo 'Finished building binary: $@'
	@ echo ' '

./objects/%.o: ./*.cpp ./*.hpp
	@ echo 'Building target using G++ compiler: $<'
	$(CC) $< $(CC_FLAGS) -o $@
	@ echo ' '

./objects/main.o: ./main.cpp (HPP_SOURCE)
@ echo 'Building target using G++ compiler: $<'
	$(CC) $< $(CC_FLAGS) -o $@
	@ echo ' '

clean:
	@ $(RM) ./*.o $(PROJ_NAME) *~
	
run:    all
	./Matriz


.TUDO: all clean
