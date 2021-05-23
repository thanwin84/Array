//time: O(nlogn) and space: O(1)
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m) {
        //code
        sort(a.begin(), a.end());
        long long result = LONG_MAX;
        int left = 0;
        int right = m - 1;
        while (right < n) {
            if (a[right] - a[left] < result) result = a[right] - a[left];
            left++;
            right++;
        }
        return result;

        }
};
