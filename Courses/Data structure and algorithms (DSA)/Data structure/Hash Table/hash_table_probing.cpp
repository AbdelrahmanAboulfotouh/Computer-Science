#include<iostream>
#include <vector>
#include <bits/stdc++.h>
#include<cassert>
using namespace std;

int hash_string(string str, int n = 65407) {
    long long nn = n;
    long long sum = 0;
    for (int i = 0; i < (int) str.size(); ++i)
        sum = (sum * 26 + str[i] - 'a') % nn;
    return sum % nn;
}

struct PhoneEntry {
    const static int INTERNAL_LIMIT = 65407;
    string name;			// key
    string phone_number;	// data

    int hash() {
        return hash_string(name, INTERNAL_LIMIT);
    }

    PhoneEntry(string name, string phone_number) :
            name(name), phone_number(phone_number) {
    }

    void print() {
        cout << "(" << name << ", " << phone_number << ")  ";
    }
};


class PhoneHashTable {
private:
    int table_size;
    vector<PhoneEntry*> table;
    // to mark a cell as deleted
    PhoneEntry *deleted {};
public:
    PhoneHashTable(int table_size) :
            table_size(table_size) {
        table.resize(table_size);
        deleted = new PhoneEntry("", "");
    } //  needs a destructor

    bool put(PhoneEntry phone) {
        int idx = phone.hash() % table_size;
        // We max move table_size steps
        for (int step = 0; step < table_size; ++step) {
            if (table[idx] == deleted || !table[idx]) {	// empty
                table[idx] = new PhoneEntry(phone.name, phone.phone_number);
                return true;
            } else if (table[idx]->name == phone.name) {
                table[idx]->phone_number = phone.phone_number;
                return true;	// update
            }
            idx = (idx + 1) % table_size;	// move next
        }
        return false;	// can't insert. Full table
    }

    bool remove(PhoneEntry phone) {
        int idx = phone.hash() % table_size;

        for (int step = 0; step < table_size; ++step) {
            if(!table[idx])
                break;
            if (table[idx] != deleted && table[idx]->name == phone.name) {
                delete table[idx];
                table[idx] = deleted;
                return true;
            }
            idx = (idx + 1) % table_size;	// move next
        }
        return false;
    }

    bool get(PhoneEntry &phone) {
        int idx = phone.hash() % table_size;

        for (int step = 0; step < table_size; ++step) {
            if(!table[idx])
                break;
            if (table[idx] != deleted && table[idx]->name == phone.name) {
                phone.phone_number = table[idx]->phone_number;
                return true;
            }
            idx = (idx + 1) % table_size;	// move next
        }
        return false;
    }

    void print_all() {
        for (int hash = 0; hash < table_size; ++hash) {
            cout << hash << " ";
            if (table[hash] == deleted)
                cout << " X ";
            else if (!table[hash])
                cout << " E ";
            else
                table[hash]->print();
            cout << "\n";
        }
        cout << "******************\n";
    }
};

