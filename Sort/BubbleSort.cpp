#include <functional>
#include <iostream>
#include <vector>

#define SWAP(a, b) \
    {              \
        a = a ^ b; \
        b = a ^ b; \
        a = a ^ b; \
    }
using namespace std;


//版本一
void bubbleSort(vector<int>& A, function<bool(int, int)> const& call) {
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < A.size() - 1; ++i) {
            if (!call(A[i], A[i + 1])) {
                SWAP(A[i], A[i + 1]);
                sorted = false;
            }
        }
    }
}

int main(void) {
    vector<int> nums = {10, 2, 44, 8, 26, 9, 115, 16, 18, 38};
    auto fun = [](int a, int b) { return a < b; };
    bubbleSort(nums, fun);
    for (auto i : nums)
        cout << i << "   ";
    getchar();
    return 0;
}