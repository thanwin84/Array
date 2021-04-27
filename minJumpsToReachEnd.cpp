class Solution{
public:
    int minJumps(int arr[], int n){
        // Your code here
        if (n == 1){
            return 0;
        }
        if (arr[0] == 0){
            return -1;
        }
        int ladder = arr[0];
        int stairs = arr[0];
        int jumps = 1;
        for (int step = 1; step < n; step++){
            if (step == n -1){
                return jumps;
            }
            if (step + arr[step] > ladder){
                ladder = step + arr[step];
            }
            stairs -= 1;
            if (stairs == 0){
                jumps += 1;
                if (step == ladder){
                    return -1;
                }
                stairs =  ladder - step;
            }
        }
        return jumps;
    }
};
