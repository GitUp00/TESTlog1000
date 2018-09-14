/* 
 * File:   HashNode.h
 * Author: bram
 *
 * Created on November 8, 2015, 8:39 AM
 */

#ifndef HASHNODE_H
#define	HASHNODE_H

#include <string>

class HashNode {
public:

 HashNode(const std::string &key, const int &value) :
  key(key), value(value), next(NULL) {}

  std::string getKey() const {
    return key;
  }
  
  int getValue() const {
    return value;
  }
  
  void setValue(int value) {
    HashNode::value = value;
  }
  
  HashNode *getNext() const {
    return next;
  }
  
  void setNext(HashNode *next) {
    HashNode::next = next;
  }
  
 private:
  // key-value pair
  std::string key;
  int value;
  
  // next bucket with the same key
  HashNode *next;
};

#endif	/* HASHNODE_H */

