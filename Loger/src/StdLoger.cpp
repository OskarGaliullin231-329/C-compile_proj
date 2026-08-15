#include "../include/StdLoger.hpp"

#include <iostream>

void StdLoger::addEvent(size_t line, const std::string& comm) {
  _events.push_back({line, comm});
}

void StdLoger::removeEvents() {
  _events.clear();
}

void StdLoger::loadEvents() {
  for (const auto& event : _events) {
    std::cout << "in '" << _f_name << "' at line" << event._line << ":\n";
    std::cout << event._comm << '\n';
  }
}
