class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0=1;
        int row=matrix.size(), col=matrix[0].size();
        for(int i=0;i<row;i++){
            if(matrix[i][0]==0)
                col0=0; //PEHLE COLOUMN K LIYE
            for(int j=1;j<col;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=row-1;i>=0;i--){
            for(int j=col-1;j>=1;j--){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
            if(col0==0)
                matrix[i][0]=0;
        }
    }
};
// test case for dry run
// 0 1 2 0
// 3 4 5 2
// 1 3 1 5

// OUTPUT:===

// 0 0 0 0
// 0 4 5 0
// 0 3 1 0
