#include <iostream>
#include <vector>

#define SWAP(a, b) \
    {              \
        int t = a; \
        a = b;     \
        b = t;     \
    }

using namespace std;

//[lo,hi)
//第一版Partition
int Partition(vector<int>& A, int lo, int hi) {
    int pivot = A[lo], i = lo + 1, j = hi - 1;
    while (i < j) {
        if (A[j] < pivot) {
            SWAP(A[i], A[j]);
            ++i;
        } else
            --j;
    }
    int p = A[i] < A[lo] ? i : i - 1;
    swap(A[lo], A[i] < A[lo] ? A[i] : A[i - 1]);
    return p;
}

void QuickSort(vector<int>& A, int lo, int hi) {
    if (lo + 1 >= hi)
        return;
    int p = Partition(A, lo, hi);
    QuickSort(A, lo, p);
    QuickSort(A, p + 1, hi);
}

int main(void) {
    vector<int> nums = {10, 2, 44, 8, 26, 19, 115, 16, 18, 38};
    QuickSort(nums, 0, nums.size());
    for (auto i : nums)
        cout << i << "   ";
    getchar();
    return 0;
}