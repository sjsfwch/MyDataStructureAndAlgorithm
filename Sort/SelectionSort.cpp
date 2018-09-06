#include <iostream>
#include <vector>
using namespace std;

#define SWAP(a, b) \
    {              \
        int t = a; \
        a = b;     \
        b = t;     \
    }

void selectionSort(vector<int>& A) {
    for (int i = 0; i < A.size(); ++i) {
        int j = i, min = i;
        while (j < A.size()) {
            min = A[j] < A[min] ? j : min;
            ++j;
        }
        SWAP(A[i], A[min]);
    }
}

int main(void) {
    vector<int> nums = {10, 2, 44, 8, 26, 9, 115, 16, 18, 38};
    selectionSort(nums);
    for (auto i : nums)
        cout << i << "   ";
    getchar();
    return 0;
}