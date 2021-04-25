//int the worst case the min num of comparison is 2(n-1) when the array is sorted in non inreasing order
//and the best case is O(n-1) when the array is sorted in increasing order
pair<int, int> minComparison(vector<int> & arr){
    int min = arr[0];
    int max = arr[0];
    for (int i = 1; i < arr.size(); i++){
        if (arr[i] > max) max = arr[i];
        else if (arr[i] < min) min = arr[i];
    }
    return {min, max};
 // in the worst and best case total comparison is 3n/2 which is less than 2(n-1)
 pair<int, int> minComparison(vector<int> & arr){
    int min, max, start;
   //checking boundary cases
    if (arr.size() % 2 != 0){
        min = arr[0];
        max = arr[0];
        start = 1;
    }
    if (arr.size() % 2 == 0){
        if (arr[0] > arr[1]){
            max = arr[0];
            min = arr[1];
            start = 2;
        }
        else {
            max = arr[1];
            min = arr[0];
            start = 2;
        }
    }
    int i = start;
    while (i < arr.size()){
        if (arr[i] > arr[i+1]){
            if (max < arr[i]) max= arr[i];
            if (min > arr[i+1]) min = arr[i+1];
            i += 2;
        }
        else {
            if (max < arr[i+1]) max = arr[i+1];
            if (min > arr[i]) min = arr[i];
            i += 2;
        }
    }
    return {min, max};
}
  // total number of comparison 3n/2 - 2
    pair<int, int> minComparison(vector<int> & arr, int start, int end){
    int min, max;
    if (start +1 == end){
        if (arr[start] < arr[end]){
            min = arr[start];
            max = arr[end];
            return {min, max};
        }
        else{
            min = arr[end];
            max = arr[start];
            return {min, max};
        }
    }
    if (start == end){
        min = arr[start];
        max = arr[start];
        return {min, max};
    }
    int mid = start + (end - start)/2;
    pair<int, int> firstP = minComparison(arr, start, mid);
    pair<int, int> secondP = minComparison(arr, mid+ 1, end);
    if (firstP.first < secondP.first){
        min = firstP.first;
    }
    else {
        min = secondP.first;
    }
    if (firstP.second > secondP.second){
        max = firstP.second;
    }
    else {
        max = secondP.second;
    }
    return {min, max};

}
