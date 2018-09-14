#include "HashMap.h"

using namespace std;

const int HashMap::TABLE_SIZE = 50;

HashMap::~HashMap() {
    // destroy all buckets one by one
    for (int i = 0; i < TABLE_SIZE; ++i) {
        HashNode *entry = table[i];
        while (entry != NULL) {
            HashNode *prev = entry;
            entry = entry->getNext();
            delete prev;
        }
        table[i] = NULL;
    }
    // destroy the hash table
    delete [] table;
}

bool HashMap::get(const std::string &key, int &value) {
    int hashValue = hashFunc(key);
    HashNode *entry = table[hashValue];

    while (entry != NULL) {
        if (entry->getKey() == key) {
            value = entry->getValue();
            return true;
        }
        entry = entry->getNext();
    }
    return false;
}

void HashMap::put(const std::string &key, const int &value) {
    int hashValue = hashFunc(key);
    HashNode *prev = NULL;
    HashNode *entry = table[hashValue];

    while (entry != NULL && entry->getKey() != key) {
        prev = entry;
        entry = entry->getNext();
    }

    if (entry == NULL) {
        entry = new HashNode(key, value);
        if (prev == NULL) {
            // insert as first bucket
            table[hashValue] = entry;
        } else {
            prev->setNext(entry);
        }
    } else {
        // just update the value
        entry->setValue(value);
    }
}

void HashMap::remove(const std::string &key) {
    int hashValue = hashFunc(key);
    HashNode *prev = NULL;
    HashNode *entry = table[hashValue];

    while (entry != NULL && entry->getKey() != key) {
        prev = entry;
        entry = entry->getNext();
    }

    if (entry == NULL) {
        // key not found
        return;
    } else {
        if (prev == NULL) {
            // remove first bucket of the list
            table[hashValue] = entry->getNext();
        } else {
            prev->setNext(entry->getNext());
        }
        delete entry;
    }
}

void HashMap::shallow_copy(HashNode** data){
    
    for(int i=0;i<TABLE_SIZE;i++){
        table[i]=data[i];
    }
    
}

std::vector<std::string> HashMap::getKeys() const{
  std::vector<std::string> res;
  
  for(int i=0;i<TABLE_SIZE;i++){
    HashNode *entry = table[i];
    
    while (entry != NULL) {
      res.push_back(entry->getKey());
      entry = entry->getNext();
    }
  }

  return res;
}


int HashMap::compter(const std::string& key) {
  int value;
  // si la cle existe, incrementer la valeur
  if(this -> get(key,value))
	value ++;
  //sinon, ajouter la cle avec la valeur 1
  else
	value = 1;

 // Stocker la cle et sa valeur dans le hashMap
 // TODO...
  put(key,value);
  return value;
}

