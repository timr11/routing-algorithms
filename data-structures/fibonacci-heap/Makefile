CXXFLAGS     = -g -Wall -std=c++17 -pthread
CXX          = g++
OBJDIR       = obj
OBJ          = $(addprefix $(OBJDIR)/, $(patsubst %.cpp, %.o, $(wildcard *.cpp)))
TARGET       = fib-heap

.PHONY: all clean debug

all: $(OBJDIR) $(TARGET)

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJDIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	@rm -f $(TARGET) $(wildcard *.o) $(wildcard *.log)
	@rm -rf $(OBJDIR)

