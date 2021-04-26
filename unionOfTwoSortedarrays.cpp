//time: O(n+m) and space: O(n+m)
class Solution{
public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        //code here
        unordered_map<int, int> table;
        for(int i = 0; i < n; i++){
            table[a[i]] = 1;
        }
        for (int i = 0; i < m; i++){
            table[b[i]] = 1;
        }
        return table.size();
    }
};
