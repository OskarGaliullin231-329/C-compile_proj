#ifndef LOGER_HPP_
#define LOGER_HPP_

#include <string>

template <class Type>
class Loger {
public:
  void addEvent(const std::string& f_name, std::size_t line, const std::string& comm) {
    static_cast<Type*>(this)->addEvent(f_name, line, comm);
  }
  void removeEvents() {
    static_cast<Type*>(this)->removeEvents();
  }
  void loadEvents() {
    static_cast<Type*>(this)->loadEvents();
  }

protected:
  struct Event {
    std::string _f_name;
    std::size_t _line;
    std::string _comm;
  };
};

#endif // LOGER_HPP_
