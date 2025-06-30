CXX = g++
CXXFLAGS = -Wall -std=c++17 -I.

OUTPUT_DIR = output
ICOLLECTION_DIR = ICollection
INTERFACES_DIR = $(ICOLLECTION_DIR)/interfaces
COLLECTIONS_DIR = $(ICOLLECTION_DIR)/collections

OBJS = \
	$(OUTPUT_DIR)/main.o \
	$(OUTPUT_DIR)/Abierto.o \
	$(OUTPUT_DIR)/Cerrado.o \
	$(OUTPUT_DIR)/Control.o \
	$(OUTPUT_DIR)/motor.o

$(OUTPUT_DIR)/main: $(OBJS)
	$(CXX) $(CXXFLAGS) -mconsole $^ -o $@

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
