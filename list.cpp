#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    list<int> coll;

    // insert elements from 1 to 9
    for (int i=1; i<=9; ++i) {
        coll.push_back(i);
    }

    // find position of element with value 3
    list<int>::iterator pos;
    pos = find (coll.begin(), coll.end(),    // range
                3);                         // value

    // reverse the order of elements between found element and end
    reverse (pos, coll.end());

    // print all elements
    for (pos=coll.begin(); pos!=coll.end(); ++pos) {
        cout << *pos << ' ';
    }
    cout << endl;
}