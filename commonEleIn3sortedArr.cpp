// time: O(max(n1, n2, n3)) and space: O(n1 + n2 + n3)
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
// time: O(n1 + n2 + n3) and space: O(1)
class Solution{
public:
    vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3){
        vector<int> result;
        int i = 0,j = 0, k = 0;
        while (i < n1 and j < n2 and k < n3){
            if (A[i] == B[j] and B[j] == C[k]){
                result.push_back(A[i]);
                i++; j++; k++;
            }
            //if any element is less than any element, increment that pointer so that we get same element in future
            else if(A[i] < B[j]) i++;
            else if (B[j] < C[k]) j++;
            else k++;
            int x = A[i-1];
            // checking duplicates
            while (i < n1 and x == A[i]) i++;
            int y = B[j-1];
            while (j < n2 and y == B[j]) j++;
            int z = C[k -1];
            while (k < n3 and z == C[k]) k++;
        }
        return result;
    }
};
