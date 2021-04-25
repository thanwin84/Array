// dutch national flag algorithm
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void swap(vector<int> & arr, int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    void sortColors(vector<int>& nums) {
        int pivot = 1;
        int pIndex = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] < pivot){
                swap(nums, i, pIndex);
                pIndex += 1;
            }
        }
        pIndex = nums.size() -1;
        for(int i = nums.size()-1; i >= 0; i--){
            if (nums[i] > pivot){
                swap(nums, i, pIndex);
                pIndex -= 1;
            }
        }

    }
};
