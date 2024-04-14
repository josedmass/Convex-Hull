CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/FechoConvexo.o $(OBJ)/Ponto-e-Fecho.o $(OBJ)/Sorts.o $(OBJ)/PilhaEncadeada.o 
HDRS = $(INC)/FechoConvexo.h $(INC)/Ponto-e-Fecho.h $(INC)/Sorts.h $(INC)/PilhaEncadeada.h $(INC)/Excecoes.h
CFLAGS = -Wall -c -I$(INC)

EXE = $(BIN)/main

fecho: $(EXE)
	./$(EXE) $(filter-out $@,$(MAKECMDGOALS))

$(BIN)/main: $(OBJS)
	$(CC) -pg -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/FechoConvexo.o: $(HDRS) $(SRC)/FechoConvexo.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/FechoConvexo.o $(SRC)/FechoConvexo.cpp

$(OBJ)/Ponto-e-Fecho.o: $(HDRS) $(SRC)/Ponto-e-Fecho.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Ponto-e-Fecho.o $(SRC)/Ponto-e-Fecho.cpp

$(OBJ)/Sorts.o: $(HDRS) $(SRC)/Sorts.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Sorts.o $(SRC)/Sorts.cpp

$(OBJ)/PilhaEncadeada.o: $(HDRS) $(SRC)/PilhaEncadeada.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/PilhaEncadeada.o $(SRC)/PilhaEncadeada.cpp
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out