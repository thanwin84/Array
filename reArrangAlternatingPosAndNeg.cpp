void rotate(vector<int> &arr, int from, int to){
        int value = arr[to];
        for (int i = from; i <= to; i++){
            int temp = arr[i];
            arr[i] = value;
            value = temp;
        }
}
void reArrange(vector<int> &arr){
    int n = arr.size();
    int i = 0;
    int j = 0;
    while (j < n){
        if (i % 2 == 0 and arr[i] < 0){
            i++;
            continue;
        }
        else if (i % 2 != 0 and arr[i] > 0){
            i++;
            continue;
        }
        else{
            // to search negative value
            if (arr[i] > 0){
                j = i + 1;
                while (j < n and arr[j] >= 0){
                    j++;
                }
                if (j >= n){
                    break;
                }
                else {
                    rotate(arr, i, j);
                }
            }
            else {
                //to search negative value
                j = i +1;
                while (j < n and arr[j] < 0){
                    j++;
                }
                if (j >= n){
                    break;
                }
                else {
                    rotate(arr, i, j);
                }
            }
        }
    }
}
