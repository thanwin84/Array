int PalinArray(int arr[], int n)
{  
    for(int i = 0; i < n; i++){
        int item = arr[i];
        int ans = 0;
        while (item > 0){
            int remainder = item % 10;
            item = item / 10;
            ans = ans * 10 + remainder;
        }
        if (ans != arr[i]){
            return 0;
        }
        
    }
    return 1;
