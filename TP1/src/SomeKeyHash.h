#ifndef SOMEKEYHASH_H
#define SOMEKEYHASH_H

#include <string>

class SomeKeyHash {
public: 
  SomeKeyHash(const int& m);
    
  int operator()(const std::string& s) const;
private:
    int modu;

    unsigned long hash(const char *str) const;
};

#endif
