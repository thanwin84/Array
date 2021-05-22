class Solution {
public:
    // arr[] : the input array
    // N : size of the array arr[]

    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        //Your code here
        unordered_map<int, int> lookup;
        int result = INT_MIN;
        int total = 0;
        for (int i = 0; i < N; i++) {
            lookup[arr[i]] = 1;
        }
        for (int i = 0; i < N; i++) {
            if (lookup.count(arr[i] - 1)) {
                continue;
            }
            else {
                int count = 0;
                int item = arr[i];
                while (true) {
                    if (lookup.count(item)) {
                        count++;
                    }
                    else {
                        break;
                    }
                    item++;
                }
                total += count;
                if (count > result) result = count;
            }
            if (total == N) {
                break;
            }
        }
        return result;

    }
};
