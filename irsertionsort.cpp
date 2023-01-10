#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int> &v) {
    for (int i = 1; i < v.size(); i++) {
        int j = i;
        while (j > 0 && v[j] < v[j - 1]) {
            swap(v[j], v[j - 1]);
            j--;
        }
    }
}

int main() {
    vector<int> v = {5, 4, 3, 2, 1};
    insertionSort(v);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}
