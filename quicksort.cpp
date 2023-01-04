#include <iostream>
#include <vector>

using namespace std;

void quicksort(vector<int> &v, int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = v[(left + right) / 2];

    /* partition */
    while (i <= j) {
        while (v[i] < pivot)
            i++;
        while (v[j] > pivot)
            j--;
        if (i <= j) {
            tmp = v[i];
            v[i] = v[j];
            v[j] = tmp;
            i++;
            j--;
        }
    };

    /* recursion */
    if (left < j)
        quicksort(v, left, j);
    if (i < right)
        quicksort(v, i, right);
}

int main() {
    vector<int> v;
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);
    v.push_back(5);
    v.push_back(4);
    quicksort(v, 0, v.size() - 1);
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
    return 0;
}