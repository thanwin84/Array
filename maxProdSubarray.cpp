class Solution{
public:
    long long maxProduct(int *arr, int n){
        long long maxE = arr[0];
        long long minE = arr[0];
        long long result = arr[0];
        for(int i = 1; i < n; i++){
            long long temp = maxE;
            maxE = max<long long>(arr[i], max<long long>(maxE * arr[i], minE * arr[i]));
            minE = min<long long>(arr[i], min<long long>(temp * arr[i], minE * arr[i]));
            result = max<long long>(result, maxE);
        }
        return result;
    }
};
