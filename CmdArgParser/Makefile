CXX = clang++

HEADERS = include/CmdArgParser.hpp
SRCS = src/CmdArgParser.cpp

OBJS = $(SRCS:src/%.cpp=objs/%.o)

$(OBJS): $(SRCS) $(HEADERS)
	$(CXX) -c $(SRCS) -o $(OBJS)
