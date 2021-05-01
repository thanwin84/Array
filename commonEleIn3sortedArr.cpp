class Solution{
public:
    vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3){
        unordered_map<int, int> table;
        unordered_map<int, int> table2;
        unordered_map<int, int> table3;
        int _max = max(n1, max(n2, n3));
        for (int i = 0; i < _max; i++){
            if (i < n1 and !table.count(A[i])){
                table[A[i]] += 1;
            }
            if (i < n2 and !table2.count(B[i])){
                table2[B[i]] += 1;
            }
            if (i < n3 and !table3.count(C[i])){
                table3[C[i]] += 1;
            }
        }
//        for (auto i: table3){
//            cout << i.first << endl;
//        }
        vector<int> result;
        for (int i = 0; i < n1; i++){
            if (table.count(A[i]) and table2.count(A[i]) and table3.count(A[i])){
                result.push_back(A[i]);
                table.erase(A[i]);
            }
        }
        return result;
    }
};
