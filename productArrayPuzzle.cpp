//time: O(n) and space O(1)
// Using division method
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output;
        int product = 1;
        int flag = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == 0){
                flag++;
            }
            else {
                product *= nums[i];
            }
        }
        for (auto &i: nums){
            if (flag > 1){
                output.push_back(0);
            }
            else if (flag == 1 and i == 0){
                output.push_back(product);
            }
            else if(flag == 1 and i != 0){
                output.push_back(0);
            }
            else {
                output.push_back(product/i);
            }
        }
        return output;


    }
};
// time: O(N) and space: O(2n)
//without using division
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output;
        int product = 1;
        vector<int> left;
        vector<int> right(nums.size(), 10);
        for (int i = 0; i < nums.size(); i++){
            product *= nums[i];
            left.push_back(product);
        }
        product = 1;
        for (int i = nums.size() -1; i >= 0; i--){
            product *= nums[i];
            right[i] = product;
        }
        for (int i =0; i < nums.size(); i++){
            if (i == 0){
                output.push_back(right[1]);
            }
            else if(i == nums.size() -1){
                output.push_back(left[nums.size()-2]);
            }
            else {
                output.push_back(left[i-1] * right[i+1]);
            }
        }
        return output;
    }
};
// time:O(n) and space O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output;
        int product = 1;
        for (int i = 0; i < nums.size(); i++){
            product *= nums[i];
            output.push_back(product);
        }
        product = 1;
        for(int i = nums.size()-1; i >= 0; i--){
            if (i == nums.size()-1){
                output[i] = output[nums.size()-2];
                product *= nums[i];
            }
            else if (i == 0){
                output[i] = product;
            }
            else {
                output[i] = output[i-1] * product;
                product *= nums[i];
            }

        }
        return output;
    }
};
