class Solution {
public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        if (n== 1){
            return 0;
        }
        int result = INT_MAX;
        vector<int> visited(n, 0);
        vector<pair<int, int>> pairs;
        for (int i = 0; i < n; i++){
            if (arr[i] - k >= 0) pairs.push_back({arr[i] - k, i});
            pairs.push_back({arr[i] + k, i});
        }
        sort(pairs.begin(), pairs.end());
//        for (auto i: pairs){
//            cout << "( "<<i.first << " " << i.second << " )" ;
//        }
        int i = 0;
        int j = 0;
        int size = pairs.size();
        int count = 0;
        while (count < n and j < size){
            if (visited[pairs[j].second] == 0) count++;
            visited[pairs[j].second] += 1;
            j++;
        }
        int ans = pairs[j-1].first - pairs[i].first;
        while (j < size){

            if (visited[pairs[i].second] == 1){
                count--;
            }
            visited[pairs[i].second] -= 1;
            i++;

            while (count < n and j < size){
                if (visited[pairs[j].second] == 0) count++;
                visited[pairs[j].second] += 1;
                j++;
            }
            if (count == n){
                ans = min(ans, pairs[j-1].first - pairs[i].first);
            }


        }
        return ans;

    }
};
