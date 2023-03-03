#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// https://en.wikipedia.org/wiki/Binary_search_algorithm
 
void binary_search(vector<int>& arr, int target) {
    int L = 0, R = arr.size() - 1;
    while (L <= R) {  // must be less or equal
        int M = L + floor((R - L) / 2.0);
        if (arr[M] > target) {
            R = M - 1;
        } else if (arr[M] < target) {
            L = M + 1;
        } else {
            cout << "find " << target << " in arr[" << M << "]" << endl;
            return;
        }
    }
    cout << "unsuccessful!" << endl;
}
 
void binary_search_less_comparison(vector<int>& arr, int target) {
    int L = 0, R = arr.size() - 1;
    while (L != R) {                      // must be not equal
        int M = L + ceil((R - L) / 2.0);  // must be round to up
        if (arr[M] > target) {            // must be arr[M] > target
            R = M - 1;
        } else {
            L = M;
        }
    }
    if (arr[L] == target) {
        cout << "find " << target << " in arr[" << L << "]" << endl;
        return;
    }
    cout << "unsuccessful!" << endl;
}
 
void binary_search_leftmost(vector<int>& arr, int target) {
    int L = 0, R = arr.size();  // R must be arr.size()
    while (L < R) {             // must be less
        int M = L + floor((R - L) / 2.0);
        if (arr[M] < target) {  // must be arr[M] < target
            L = M + 1;          // L must be M + 1
        } else {
            R = M;
        }
    }
    if (arr[L] == target) {
        cout << "find left most " << target << " in arr[" << L << "]" << endl;
        return;
    }
    cout << "unsuccessful!" << endl;
}
 
void binary_search_rightmost(vector<int>& arr, int target) {
    int L = 0, R = arr.size();  // R must be arr.size()
    while (L < R) {             // must be less
        int M = L + floor((R - L) / 2.0);
        if (arr[M] > target) {  // must be arr[M] > target
            R = M;              // R must be M
        } else {
            L = M + 1;
        }
    }
    if (arr[R - 1] == target) {
        cout << "find right most " << target << " in arr[" << R - 1 << "]"
             << endl;
        return;
    }
    cout << "unsuccessful!" << endl;
}
 
int main() {
    // Non-decreasing Array
    vector<int> vec{1, 2, 4, 4, 4, 5, 6, 7};
 
    binary_search(vec, 4);
    binary_search_less_comparison(vec, 4);
    binary_search_leftmost(vec, 4);
    binary_search_rightmost(vec, 4);
 
    return 0;
}
