#include <vector>
#include <functional>
#include <iostream>
using namespace std;

//版本一
void bubbleSort(vector<int> &A,function<bool(int,int)> const& call){
    bool sorted = false;
    while(!sorted){
        sorted = true;
        for (int i = 0; i < A.size() - 1;++i){
            if(!call(A[i],A[i+1])){
                int temp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = temp;
                sorted = false;
            }
        }
    }

}

int main(void){
    vector<int> nums = {1, 2, 4, 8, 6, 9, 15, 16, 18, 38};
    auto fun = [](int a, int b) { return a < b; };
    bubbleSort(nums,fun);
    for(auto i:nums)
        cout << i << "   ";
    return 0;
}