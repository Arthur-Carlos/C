# Nome do executável final
TARGET = sistema_escolar

# Compilador e flags
CC = gcc
CFLAGS = -Wall -g

# Fontes e objetos
SRCS = main.c pessoas.c disciplinas.c
OBJS = $(SRCS:.c=.o)

# Regra principal
all: $(TARGET)

# Como criar o executável
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Como compilar os .c em .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza dos arquivos
clean:
	rm -f $(TARGET) *.o

# Rodar o programa
run: $(TARGET)
	./$(TARGET)
