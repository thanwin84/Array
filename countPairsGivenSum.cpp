class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        unordered_map<int, int> lookup;
        for (int i = 0; i < n; i++){
            lookup[arr[i]] += 1;
        }
        int twice_count = 0;
        for (int i = 0; i < n; i++){
            twice_count += lookup[k - arr[i]];
            if (k - arr[i] == arr[i]){
                twice_count -= 1;
            }
        }
        return twice_count / 2;
    }
};
