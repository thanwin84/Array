//kadene's algorithm
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int meS = 0;
        int _max = INT_MIN;
        for (int i = 0; i < nums.size(); i++){
            meS = meS + nums[i];
            if (meS < nums[i]) meS = nums[i];
            if (_max < meS) _max = meS;
        }
        return _max;

    }
};
