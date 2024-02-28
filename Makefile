# Makefile générique pour un projet C++

# Compilateur C++
CXX = g++

# Options de compilation
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic

# Liste des fichiers sources (ajoutez tous vos fichiers source ici)
SOURCES = $(wildcard *.cpp)

# Liste des fichiers objets générés à partir des fichiers sources
OBJECTS = $(SOURCES:.cpp=.o)

# Nom de l'exécutable
TARGET = compiler

# Règle par défaut pour construire l'exécutable
all: $(TARGET)

# Règle pour construire l'exécutable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Règle générique pour construire les fichiers objets
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoie les fichiers objets et l'exécutable
clean:
	rm -f $(OBJECTS) $(TARGET)
