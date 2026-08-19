#include <iostream>

#include "../Logger/include/StdLogger.hpp"

using namespace std;

int main() {
  // using Logger = Logger<StdLogger>;
  Logger<StdLogger>& logger = Logger<StdLogger>::getInstance();
  logger.configure("Testing");
  logger.addEvent(Event(0, "Message 1"));
  logger.loadEvents();
  // cout << sizeof(Logger<StdLogger>) << '\n';
  // cout << sizeof(StdLogger) << '\n';
  return 0;
}
