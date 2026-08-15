#ifndef STDLOGER_HPP_
#define STDLOGER_HPP_

#include <list>

#include "Loger.hpp"

class StdLoger final : public Loger<StdLoger> {
public:
  void addEvent(size_t, const std::string&);
  void removeEvents();
  void loadEvents();

private:
  std::list<Loger::Event> _events;
};

#endif // STDLOGER_HPP_
