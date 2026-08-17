#ifndef EVENT_HPP_
#define EVENT_HPP_

#include <string>

class Event {
public:
  Event(size_t line, const std::string& comm): _line(line), _comm(comm) {}
  Event(const Event&) = delete;
  Event(Event&&) = delete;

public:
  size_t getLine() const { return _line; }
  std::string_view getComm() const { return _comm; }

private:
  size_t _line;
  std::string _comm;
};

#endif // EVENT_HPP_
