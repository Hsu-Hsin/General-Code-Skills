#include <iostream>
#include <queue>
#include <set>

// version 3
bool operator<(const Machine a, const Machine b);
bool operator<(const Machine& a, const Machine& b);

/*
 * wrong! can not use standard types
 * bool operator<(const Machine* a, const Machine* b);
 */

typedef class Machine {
   public:
    int id = 0;
    int pt = 0;

    Machine() {}
    Machine(int ID, int PT) : id(ID), pt(PT) {}

    // version 1
    bool operator<(const Machine m) const;
    bool operator<(const Machine& m) const;
    bool operator<(const Machine* m) const;

    // version 2
    friend bool operator<(const Machine a, const Machine b);
    friend bool operator<(const Machine& a, const Machine& b);

    /*
     * wrong! can not use standard types
     * friend bool operator<(const Machine* a, const Machine* b);
     *
     * wrong! too few parameters
     * friend bool operator<(const Machine a);
     * friend bool operator<(const Machine& a);
     *
     * wrong! too many parameters
     * bool operator<(const Machine a, const Machine b);
     * bool operator<(const Machine& a, const Machine& b);
     * bool operator<(const Machine* a, const Machine* b); // can not use
     * standard types
     */
} Type;

bool operator<(const Machine a, const Machine b) {
    if (a.pt != b.pt)
        return a.pt > b.pt;
    else
        return a.id > b.id;
}

bool operator<(const Machine& a, const Machine& b) {
    if (a.pt != b.pt)
        return a.pt > b.pt;
    else
        return a.id > b.id;
}

bool Machine::operator<(const Machine m) const {
    if (pt != m.pt)
        return pt > m.pt;
    else
        return id > m.id;
}

bool Machine::operator<(const Machine& m) const {
    if (pt != m.pt)
        return pt > m.pt;
    else
        return id > m.id;
}

bool Machine::operator<(const Machine* m) const {
    if (pt != m->pt)
        return pt > m->pt;
    else
        return id > m->id;
}

int main() {
    std::set<Type*> myset;
    Type* p1 = new Type(0, 2);
    Type* p2 = new Type(1, 2);
    Type* p3 = new Type(2, 3);
    myset.insert(p1);
    myset.insert(p2);
    myset.insert(p3);

    for (const auto& item : myset) {
        std::cout << item->id << " " << item->pt << std::endl;
    }

    myset.clear();
    delete p3;
    delete p2;
    delete p1;
    return 0;
}
