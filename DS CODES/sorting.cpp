#include "bits/stdc++.h";
using namespace std;
#define int long long
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------*/
void bubble_sort(vector<int>& arr) {
    /*
    best case tc = n
    avg case tc = n^2
    worst case tc = n^2
    */
    // algo
    /*
    traverse from left and compare adjacent elements and the higher one is placed at right side.
    In this way, the largest element is moved to the rightmost end at first.
    This process is then continued to find the second largest and place it and so on until the data is sorted.
    */

    int n = arr.size();
    int a[5] = {9, 5, 3, 2, 1};
    n = 5;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void insert_sort() {
    /*
    best case tc = n
    avg case tc = n^2
    worst case tc = n^2
    */
    /*
    Traverse from left to right and insert the current element to its correct position in the left part of the array.
    */
    int n = 5;
    int a[5] = {9, 5, 3, 2, 1};
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void heap_sort() {
    /*
    First convert the array into heap data structure using heapify, then one by one delete the root node of the Max-heap and replace it with the last node in the heap and then heapify the root of the heap. Repeat this process until size of heap is greater than 1.

    Build a heap from the given input array.
    Repeat the following steps until the heap contains only one element:
    Swap the root element of the heap (which is the largest element) with the last element of the heap.
    Remove the last element of the heap (which is now in the correct position).
    Heapify the remaining elements of the heap.
    The sorted array is obtained by reversing the order of the elements in the input array.
    */
    /*
     best case tc = nlogn
     avg case tc = nlogn
     worst case tc = nlogn
     */
}

void solve() {
    vector<int> arr;
    bubble_sort(arr);
}
signed main() {
    int testcase = 1;
    while (testcase--)
        solve();
}
