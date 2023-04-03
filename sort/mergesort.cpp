#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &v, int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = v[left + i];
    for (j = 0; j < n2; j++)
        R[j] = v[middle + 1 + j];

    /* Merge the temp arrays back into v[left..right]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = left; // Initial index of merged subarray
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

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1) {
        v[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2) {
        v[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(vector<int> &v, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergesort(v, left, middle);
        mergesort(v, middle + 1, right);
        merge(v, left, middle, right);
    }
}

int main() {
    vector<int> v;
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);
    v.push_back(5);
    v.push_back(4);
    mergesort(v, 0, v.size() - 1);
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
    return 0;
}