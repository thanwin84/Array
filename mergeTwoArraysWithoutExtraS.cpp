//nlogn
// using shell sort intuition
//https://youtu.be/hVl2b3bLzBw
class Solution{
public:
    int nextGap(int n){
        if (n <= 1){
            return 0;
        }
        return (n/2) + (n % 2);

    }
    void swap(int arr[], int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    void merge(int arr1[], int arr2[], int n, int m) {
        // code here
        int gap = n + m;
        gap = nextGap(gap);
        while (gap > 0){
            int i = 0;
            // swapping in the first half
            while (i + gap < n){
                if (arr1[i] > arr1[i+gap]){
                    swap(arr1, i, gap+i);
                }
                i++;
            }
            int j = 0;
            if (gap > n){
                j = gap - n;
            }
            // swapping the in the both half
            while (i < n and j < m){
                if (arr1[i] > arr2[j]){
                    int temp = arr1[i];
                    arr1[i] = arr2[j];
                    arr2[j] = temp;
                }
                i++;
                j++;
            }
//            cout << i << " " << j <<  endl;
            if (j < m){
                j = 0;
                //swapping in the last half
                while (j + gap < m) {
                    if (arr2[j] > arr2[j+gap]){
                        int temp = arr2[j];
                        arr2[j] = arr2[j+gap];
                        arr2[j + gap] = temp;
                    }
                    j++;
                }
            }
            gap = nextGap(gap);
        }

    }
};
