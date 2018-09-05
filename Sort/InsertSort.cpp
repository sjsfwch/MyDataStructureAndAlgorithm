#include <functional>
#include <iostream>
#include <vector>
using namespace std;

#define SWAP(a, b) \
    {              \
        a = a ^ b; \
        b = a ^ b; \
        a = a ^ b; \
    }

//版本一
void insertSort(vector<int>& A, function<bool(int, int)> const& call) {
    for (int i = 0; i < A.size() - 1; ++i) {
        int j = i + 1;
        while (j > 0 && call(A[j - 1], A[j])) {
            SWAP(A[j - 1], A[j]);
            --j;
        }
    }
}

int main(void) {
    vector<int> nums = {10, 2, 44, 8, 26, 9, 115, 16, 18, 38};
    auto fun = [](int a, int b) { return a > b; };
    insertSort(nums, fun);
    for (auto i : nums)
        cout << i << "   ";
    getchar();
    return 0;
}