CXX = g++
CXXFLAGS = -I.
DEPS = app.hpp todo.hpp config.hpp codec.hpp
SRC = main.cpp app.cpp todo.cpp config.cpp codec.cpp
OUT = main

$(OUT): $(SRC) $(DEPS)
	$(CXX) -o $(OUT) $(SRC) $(DEPS) $(CXXFLAGS)

.PHONY: clean
clean:
	rm -f *.o