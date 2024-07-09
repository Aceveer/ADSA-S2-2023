#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class HashTable {
private:
    vector<string> table;

    size_t getLastChar(const string& key) {
        // Just take the last character
        char lastChar = key.back();
        //Do subtraction
        return lastChar - 'a';
    }

public:
    HashTable() {
        // Empty hash table assigned
        table.assign(26, "never used");
    }

    void insert(const string& key) {
        // Checking to see if the key is already there
        size_t hashValue = getLastChar(key);
        size_t hashSlot = hashValue;

        while (true) {
            if (table[hashSlot] == key) {
                //key exists so do nothing
                return; 
            }
            else if (table[hashSlot] == "never used" || table[hashSlot] == "tombstone") {
                // insert the key if slot is never used
                table[hashSlot] = key;
                return;
            }
            else {
                //Get to the next slot if not found
                hashSlot = (hashSlot + 1) % 26;
            }
        }
    }

    void remove(const string& key) {
        // Checking to see if the key is already there
        size_t hashValue = getLastChar(key);
        size_t hashSlot = hashValue;

        while (table[hashSlot] != "never used") {
            if (table[hashSlot] == key) {
                // change status to tombstone
                table[hashSlot] = "tombstone";
                return;
            }
            else {
                // Get to the next slot if not found
                hashSlot = (hashSlot + 1) % 26;
            }
        }
    }

    void printTable() {
        for (const string& key : table) {
            if (key != "never used" && key != "tombstone") {
                cout << key << " ";
            }
        }
        cout << endl;
    }
};

int main() {
    //Creating an empty hash Table
    HashTable hashTable;

    string input;
    getline(cin, input);
    istringstream iss(input);

    string move;
    while (iss >> move) {
        char operation = move[0];
        string word = move.substr(1);

        if (operation == 'A') {
            hashTable.insert(word);
        }
        else if (operation == 'D') {
            hashTable.remove(word);
        }
    }

    // Print the keys in the hash table.
    hashTable.printTable();

    return 0;
}
