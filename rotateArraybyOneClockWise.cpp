void rotate(int arr[], int n)
{
    if (n == 1) {
        return;
    }
    int temp = arr[n-1];
    arr[n-1] = arr[n-2];
    arr[n-2] = temp;
    int value = temp;
    for (int i = 0 ; i < n-1; i++){
        if (i == 0){
            value = arr[i];
            arr[i] = temp;
        }
        else {
            int temp = arr[i];
            arr[i] = value;
            value = temp;
        }

    }
}
