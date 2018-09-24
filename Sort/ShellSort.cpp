#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>

#define SWAP(a, b) \
    {              \
        int t = a; \
        a = b;     \
        b = t;     \
    }

using namespace std;

int getSequenceStart(int n) {
    int i = 1;
    while (pow(2, i) - 1 < n)
        ++i;
    return i - 1;
}

void ShellSort(vector<int>& A) {
    int k = getSequenceStart(A.size());
    while (k >= 1) {
        int d = pow(2, k) - 1;
        for (int i = 0; i < d; ++i) {  //对d个子序列排序
            for (int j = i + d; j < A.size(); j += d) {  //间隔为d的直接插入排序
                int start = j;
                while (start >= i + d && A[start] < A[start - d]) {
                    SWAP(A[start], A[start - d]);
                    start -= d;
                }
            }
        }
        --k;
    }
}

int main(void) {
    // vector<int> nums = {10, 2, 44, 8, 26, 19, 115, 16, 18,
    // 38,87,89,7,11,95,75,12,856,94};
    vector<int> nums;
    for (int i = 0; i < 10000000; i++) {
        nums.push_back(rand());
    }
    ShellSort(nums);
    // for (auto i : nums)
    //     cout << i << "   ";
    getchar();
    return 0;
}