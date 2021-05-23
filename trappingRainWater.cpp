//time: O(n) and space: O(n)
class Solution {

    // Function to find the trapped water between the blocks.
public:
    int trappingWater(int arr[], int n) {
        // Code here
        vector<int> maxL;
        for (int i = 0; i < n; i++) {
            if (maxL.size() == 0) {
                maxL.push_back(arr[i]);
            }
            else if (maxL[i - 1] > arr[i]) {
                maxL.push_back(maxL[i - 1]);
            }
            else {
                maxL.push_back(arr[i]);
            }
        }
        vector<int> maxR(n, -1);
        maxR[n - 1] = arr[n - 1];
        for(int i = n-2; i >= 0; i--) {
            if (maxR[i + 1] > arr[i]) {
                maxR[i] = maxR[i + 1];
            }
            else {
                maxR[i] = arr[i];
            }
        }
        int result = 0;
        for (int i = 0; i < n; i++) {
            result += min(maxR[i], maxL[i]) - arr[i];
        }
        return result;
    }
   
};
