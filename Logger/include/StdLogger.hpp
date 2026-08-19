#ifndef STDLOGGER_HPP_
#define STDLOGGER_HPP_

#include "Logger.hpp"

class StdLogger final: public Logger<StdLogger> {
public:
  static StdLogger& getInstance() {
    static StdLogger instance;
    return instance;
  }

public:
  void addEvent(const Event&);
  void removeEvents();
  void loadEvents();
};

#endif // STDLOGGER_HPP_
