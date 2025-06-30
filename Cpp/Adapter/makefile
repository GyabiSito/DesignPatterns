CXX = g++
CXXFLAGS = -Wall -std=c++17 -I.

OUTPUT_DIR = output
ICOLLECTION_DIR = ICollection
INTERFACES_DIR = $(ICOLLECTION_DIR)/interfaces
COLLECTIONS_DIR = $(ICOLLECTION_DIR)/collections

OBJS = \
	$(OUTPUT_DIR)/Circulo.o \
	$(OUTPUT_DIR)/editor.o \
	$(OUTPUT_DIR)/IFigura.o \
	$(OUTPUT_DIR)/main.o \
	$(OUTPUT_DIR)/Rectangulo.o \
	$(OUTPUT_DIR)/Triangulo.o \
	$(OUTPUT_DIR)/I3DFigura.o \
	$(OUTPUT_DIR)/Esfera.o \
	$(OUTPUT_DIR)/Paralelepipedo.o \
	$(OUTPUT_DIR)/Piramide.o \
	$(OUTPUT_DIR)/icollection/Integer.o \
	$(OUTPUT_DIR)/icollection/String.o \
	$(OUTPUT_DIR)/icollection/ICollectible.o \
	$(OUTPUT_DIR)/icollection/IKey.o \
	$(OUTPUT_DIR)/icollection/OrderedKey.o \
	$(OUTPUT_DIR)/icollection/StringKey.o \
	$(OUTPUT_DIR)/icollection/List.o \
	$(OUTPUT_DIR)/icollection/ListIterator.o \
	$(OUTPUT_DIR)/icollection/ListNode.o \
	$(OUTPUT_DIR)/icollection/OrderedDictionary.o \
	$(OUTPUT_DIR)/icollection/OrderedDictionaryEntry.o \
	$(OUTPUT_DIR)/icollection/ICollection.o \
	$(OUTPUT_DIR)/icollection/IDictionary.o \
	$(OUTPUT_DIR)/icollection/IIterator.o            



all: $(OUTPUT_DIR)/main

$(OUTPUT_DIR)/main: $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Archivos principales
$(OUTPUT_DIR)/%.o: %.cpp
	@mkdir -p $(OUTPUT_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Interfaces
$(OUTPUT_DIR)/icollection/%.o: $(INTERFACES_DIR)/%.cpp
	@mkdir -p $(OUTPUT_DIR)/icollection
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Collections (List, OrderedDictionary, etc.)
$(OUTPUT_DIR)/icollection/%.o: $(COLLECTIONS_DIR)/%.cpp
	@mkdir -p $(OUTPUT_DIR)/icollection
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OUTPUT_DIR)/*.o $(OUTPUT_DIR)/icollection/*.o $(OUTPUT_DIR)/main

.PHONY: all clean

run: $(OUTPUT_DIR)/main
	./$(OUTPUT_DIR)/main
