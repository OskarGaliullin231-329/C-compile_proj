#include "../include/StdLogger.hpp"

#include <iostream>

void StdLogger::addEvent(const Event& event) {
  _events.push_back(event);
}

void StdLogger::removeEvents() {
  _events.clear();
}

void StdLogger::loadEvents() {
  for (const auto& event : _events) {
    std::cout << "in '" << _f_name << "' at line" << event.getLine() << ":\n";
    std::cout << event.getComm() << '\n';
  }
}
