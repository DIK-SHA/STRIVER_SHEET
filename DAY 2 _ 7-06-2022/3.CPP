    vector<vector<int>> generate(int n) {
        vector<vector<int>> v;
        vector<int> x(1,1);
        v.push_back(x);
        for(int i=1;i<n;i++){
            vector<int> curr(i+1,1); 
            for(int j=1;j<i;j++){
                curr[j]=v[i-1][j-1]+v[i-1][j];
            }
            v.push_back(curr);
        }
        return v;
    }

// Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
// Input: numRows = 1
// Output: [[1]]