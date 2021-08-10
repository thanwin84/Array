//O(n)
class Solution{
public:
    bool validMountainArray(vector<int>&arr) {
        if (arr.size() < 3){
            return false;
        }
        int i = 1;
        for (; i < arr.size()-1; i++) {
            if (arr[i - 1] < arr[i] and arr[i] > arr[i + 1]) {
                i++;
                break;
            }
            else if (arr[i - 1] < arr[i] and arr[i] < arr[i + 1])continue;
            else {
                return false;
            }
            
        }
        i--;
        while (i < arr.size() - 1) {
            if (arr[i] > arr[i + 1]) i++;
            else {
                return false;
            }
        }
        return true;
    }
};
//more clean code
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int N = A.size();
        int i = 0;
        //walk up
        while (i + 1 < N and A[i] < A[i + 1]){
            i++;
        }
        //peak can't be first or last
        if (i == 0 or i == N -1){
            return false;
        }
        //walk down
        while (i + 1 < N and A[i] > A[i + 1]){
            i++;
        }
        return i == N - 1;
    }
};
