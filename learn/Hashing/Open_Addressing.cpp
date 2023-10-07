#include<bits/stdc++.h>
using namespace std;

// TODO: make a function which gets next prime //
// using linear probing //
class myHash {
private:
    int capacity;
    int size;
    int *hashTable;
public:
    myHash(int c) {
        capacity = c;
        size = 0;
        for (int i = 0; i < capacity; i++) {
            hashTable[i] = -1; // declaring all are empty//
        }
    }

    int hash(int key) {
        return key % capacity;
    }

    bool insert(int key);
    bool search(int key);
    bool erase(int key);
};

bool myHash::insert(int key) {
    if (size == capacity) {
        return false;
    }
    int index = hash(key);
    while (hashTable[index] != -1 && hashTable[index] != -2 && hashTable[index] != key) {
        index = (index + 1) % capacity;
    }
    if(hashTable[index] == key){
        return false; // key already present in the hash table //
    }
    else{
        hashTable[index] = key;
        size++;
        return true;
    }
    return false;
}

bool myHash :: search(int key)
{
    int index = hash(key);
    int CircularLoop = index;
    while(hashTable[index] != -1){
        if(hashTable[index] == key){
            return true;
        }
        index = (index + 1)%capacity;
        if(CircularLoop == index){
            return false;
        }
    }
    return false;
}

bool myHash :: erase(int key){
    int index = hash(key);
    int h = index;
    while(hashTable[index] != -1){
        if(hashTable[index] == key){
            hashTable[index] = -2;
            size--; // Updating the size of Hash Table //
            return true;
        }
        index = (index + 1)%capacity;
        if(index == h){
            return false;
        }
    }
    return false;
}

int main() {
    myHash Hash(7);
    Hash.insert(32);
    cout<<Hash.search(32)<<endl;;
    Hash.erase(32);
    cout<<Hash.search(32)<<endl;
    

    return 0;
}