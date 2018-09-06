#include <iostream>
#include <vector>
using namespace std;

//版本1 merge算法
void merge(vector<int>& A, int lo, int mi, int hi) {
    int B[hi - lo], p1 = lo, p2 = mi;
    for (int i = 0; i < hi - lo; ++i) {
        if (p1 >= mi) {
            B[i] = A[p2++];
            continue;
        }
        if (p2 >= hi) {
            B[i] = A[p1++];
            continue;
        }
        B[i] = A[p1] <= A[p2] ? A[p1++] : A[p2++];
    }
    int i = 0;
    while (i < hi - lo) {
        A[i + lo] = B[i];
        ++i;
    }
}

void mergeSort(vector<int>& A, int lo, int hi) {  //[lo,hi)
    if (hi - lo <= 1)
        return;
    int mi = (lo + hi) >> 1;
    mergeSort(A, lo, mi);
    mergeSort(A, mi, hi);
    merge(A, lo, mi, hi);
}

int main(void) {
    vector<int> nums = {10, 2, 44, 8, 26, 9, 115, 16, 18, 38};
    mergeSort(nums, 0, nums.size());
    for (auto i : nums)
        cout << i << "   ";
    getchar();
    return 0;
}