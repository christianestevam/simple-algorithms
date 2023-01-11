#include <iostream>
#include <vector>
#include <queue>

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

void merge(vector<int> &v, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1);
    vector<int> R(n2);
    for (int i = 0; i < n1; i++) {
        L[i] = v[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = v[mid + 1 + i];
    }
    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            v[k] = L[i];
            i++;
        } else {
            v[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        v[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        v[k] = R[j];
        j++;
        k++;
    }
}

void timSort (vector<int> &v) {
    int n = v.size();
    int run = 32;
    for (int i = 0; i < n; i += run) {
        insertionSort(v);
    }
    for (int size = run; size < n; size = 2 * size) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = left + size - 1;
            int right = min((left + 2 * size - 1), (n - 1));
            merge(v, left, mid, right);
        }
    }
}

int main() {
    vector<int> v = {-2, 7, 15, -14, 0, 15, 0, 7, -7, -4, -13, 5, 8, -14, 12};
    timSort(v);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}
