#ifndef STDLOGGER_HPP_
#define STDLOGGER_HPP_

#include <list>

#include "Logger.hpp"

class StdLogger final: public Logger<StdLogger> {
public:
  // StdLoger(const std::string& str): Loger<StdLoger>(str) {}

public:
  void addEvent(const Event&);
  void removeEvents();
  void loadEvents();

private:
  std::list<Event> _events;
};

#endif // STDLOGGER_HPP_
