#include <iostream>
#include <list>

using namespace std;

void bubblesort(list<int> &l) {
    bool swapped = true;
    while (swapped) {
        swapped = false;
        list<int>::iterator it = l.begin();
        while (it != l.end()) {
            list<int>::iterator next = it;
            next++;
            if (next != l.end() && *it > *next) {
                int tmp = *it;
                *it = *next;
                *next = tmp;
                swapped = true;
            }
            it++;
        }
    }
}

int main() {
    list<int> l;
    l.push_back(3);
    l.push_back(2);
    l.push_back(1);
    l.push_back(5);
    l.push_back(4);
    bubblesort(l);
    for (list<int>::iterator it = l.begin(); it != l.end(); it++)
        cout << *it << " ";
    cout << endl;
    return 0;
}
