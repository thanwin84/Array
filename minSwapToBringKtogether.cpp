//time: O(n) using sliding window techniq
int minSwap(int *arr, int n, int k) {
    // Complet the function
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] <= k) {
            count++;
        }
    }
    int bad = 0;
    for (int i = 0; i < count; i++) {
        if (arr[i] > k) bad++;
    }
    int ans = bad;
    int j = count;
    for (int i = 0; i < n; i++) {
        if (j == n) {
            break;
        }
        if (arr[i] > k) bad--;
        if (arr[j] > k) bad++;
        ans = min(ans, bad);
        j++;
    }
    return ans;

    return count;
}
-
