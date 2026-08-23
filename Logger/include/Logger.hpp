#ifndef LOGGER_HPP_
#define LOGGER_HPP_

#include <list>
#include <string>

#include "Event.hpp"

template <class Type>
class Logger {
public:
  static Logger<Type>& getInstance() {
    static Logger<Type> instance;
    return instance;
  }

  void configure(const std::string_view& f_name) { _f_name = f_name; }

  void addEvent(const Event& event) {
    static_cast<Type*>(this)->addEvent(event);
  }

  void removeEvents() {
    static_cast<Type*>(this)->removeEvents();
  }

  void loadEvents() {
    static_cast<Type*>(this)->loadEvents();
  }

protected:
  Logger() = default;
  Logger(const Logger<Type>&) = delete;

  void operator=(const Logger<Type>&) = delete;

protected:
  std::string_view _f_name;
  std::list<Event> _events;
};

#endif // LOGGER_HPP_
