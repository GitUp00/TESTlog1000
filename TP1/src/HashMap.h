/* 
 * File:   HashMap.h
 * Author: bram
 *
 * Created on November 8, 2015, 8:39 AM
 */

#ifndef HASHMAP_H
#define HASHMAP_H

#include <vector>
#include "HashNode.h"
#include "SomeKeyHash.h"


class HashMap {
public:

    HashMap() : table(new HashNode *[TABLE_SIZE]),hashFunc(TABLE_SIZE) {
        // construct zero initialized hash table of size
        for(int i=0;i<TABLE_SIZE;i++) table[i]=0;
    }
    
    HashMap(HashNode** data) : table(new HashNode *[TABLE_SIZE]),hashFunc(TABLE_SIZE) {
        // construct initialized hash table of size
        shallow_copy(data);
    }

    virtual ~HashMap();

    bool get(const std::string &key, int &value);
    void put(const std::string &key, const int &value);
    void remove(const std::string &key);

    std::vector<std::string> getKeys() const;
	int compter (const std::string& key);

private:
    // hash table
    HashNode **table;
    SomeKeyHash hashFunc;
    
    void shallow_copy(HashNode** data);

    static const int TABLE_SIZE;
};

#endif	/* HASHMAP_H */

