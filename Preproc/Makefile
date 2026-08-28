CXX = clang++

HEADERS = include/Preproc.hpp
SRCS = src/Preproc.cpp

OBJS = $(SRCS:src/%.cpp=objs/%.o)

$(OBJS): $(SRCS) $(HEADERS)
	$(CXX) -c $(SRCS) -o $(OBJS)
