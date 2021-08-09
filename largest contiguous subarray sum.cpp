class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(int arr[], int n){
        int max_ending_here = 0;
        int max_so_far = INT_MIN;
        for (int i = 0; i < n; i++){
            max_ending_here += arr[i];
            if (max_ending_here < arr[i]){
                max_ending_here = arr[i];
            }
            max_so_far = max(max_so_far, max_ending_here);
        }
        return max_so_far;
        
    }
};
