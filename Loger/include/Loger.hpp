#ifndef LOGER_HPP_
#define LOGER_HPP_

#include <string>

template <class Type>
class Loger {
public:
  Loger(const std::string& f_name) { _f_name = f_name; }

  void addEvent(std::size_t line, const std::string& comm) {
    static_cast<Type*>(this)->addEvent(line, comm);
  }

  void removeEvents() {
    static_cast<Type*>(this)->removeEvents();
  }

  void loadEvents() {
    static_cast<Type*>(this)->loadEvents();
  }

protected:
  struct Event {
    std::size_t _line;
    std::string _comm;
  };

protected:
  std::string _f_name;
};

#endif // LOGER_HPP_
