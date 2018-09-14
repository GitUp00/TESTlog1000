#include "SomeKeyHash.h"

using namespace std;

SomeKeyHash::SomeKeyHash(const int& m):modu(m){}
    
int SomeKeyHash::operator()(const std::string& s) const {
  return hash(s.c_str()) % modu;
}

unsigned long SomeKeyHash::hash(const char *str) const {
  return 1;
}
