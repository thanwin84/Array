class Solution {
public:

    int sb(int arr[], int n, int x)
    {
        // Your code goes here
        int result = INT_MAX;
        int left = 0;
        int right = 0;
        int sum = 0;
        int count = 0;
        while (right < n){
            if (sum <= x) {
                count++;
                sum += arr[right];
                right++;

      
            }
            if (sum > x) {
                result = min(result, count);
                while (sum > x) {
                    count--;
                    sum -= arr[left];
                    if (sum > x) result = min(result, count);
                    left++;
                }
            }
           
        }
        if (sum > x) result = min(result, count);
        return result;
    }
};
