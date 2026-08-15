#include "../include/StrIter.hpp"

StrIter::StrIter(const std::string& str) {
  _buff = str;
  _iter = _buff.begin();
  _curr_line = 0;
}

StrIter::StrIter(const StrIter& other) {
  _buff = other._buff;
  _iter = other._buff.begin();
  _curr_line = other._curr_line;
}

StrIter StrIter::operator++(int) {
  if (_iter != _buff.end()) {
    _iter++;
    if (*_iter == '\n') { _curr_line++; }
  }
  return *this;
}

StrIter StrIter::operator--(int) {
  if (_iter != _buff.begin()) {
    if (*_iter == '\n') { _curr_line--; }
    _iter--;
  }
  return *this;
}

char StrIter::operator*() {
  if (_iter == _buff.end()) { return '\0'; }
  return *_iter;
}
