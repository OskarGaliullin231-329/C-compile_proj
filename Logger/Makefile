CXX = clang++

HEADERS = include/Logger.hpp include/Event.hpp include/StfLogger.hpp
SRCS = src/Logger.cpp

OBJS = $(SRCS:src/%.cpp=objs/%.o)

$(OBJS): $(SRCS) $(HEADERS)
	$(CXX) -c $(SRCS) -o $(OBJS)
