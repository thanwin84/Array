// randomized quick select
// if we dont use randomized version, the worst time complexity will be O(n^2)
// time: O(n)
class Solution {
public:
    int partitionIndex(int arr[], int start, int end){
        int pivot = arr[end];
        int index = start;
        for (int i = start; i < end; i++){
            if (arr[i] < pivot){
                swap(arr, i, index);
                index++;
            }
        }
        swap(arr, index, end);
        return index;
    }
    void swap(int arr[], int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    int kthSmallest(int arr[], int start, int end, int k){
        while (start < end) {
            srand(time(nullptr));
            int random = start + rand() % (end - start);
            swap(arr, random, end);
            int pos = partitionIndex(arr, start, end);
            if (pos == k - 1) {
                return arr[pos];
            } else if (k - 1 > pos) {
                start = pos + 1;
            } else {
                end = pos - 1;
            }
        }
        return arr[start];
    }
};
