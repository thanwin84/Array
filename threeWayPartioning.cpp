void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void threeWayPartition(int arr[], int n, int a, int b)
{
    int low = 0;
    int high = n - 1;
    for (int i = 0; i <= high; i++) {
        if (arr[i] < a) {
            swap(arr, i, low);
            low++;
        }
        else if (arr[i] > b) {
            swap(arr, i, high);
            high--;
            i--;
        }
    }
}
