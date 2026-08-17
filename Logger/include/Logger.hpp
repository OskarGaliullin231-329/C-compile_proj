#ifndef LOGGER_HPP_
#define LOGGER_HPP_

#include <memory>
#include <string>

#include "Event.hpp"

template <class Type>
class Logger {
public:
  // class Event;

  std::shared_ptr<Logger<Type>> getInstance() {
    static Logger<Type> instance;
    return std::make_shared<Logger<Type>>(instance);
  }

  void configure(const std::string& f_name) { _f_name = f_name; }

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
  Logger() {}

protected:
  std::string _f_name;
};

#endif // LOGGER_HPP_
