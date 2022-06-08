//ROTATE MATRIX
//BRUTE FORCE - EXTRA SPACE
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> matrix2;
        int col=matrix.size(),row=matrix.size();
        for(int j=0;j<col;j++){
            vector<int> temp;
            for(int i=row-1;i>=0;i--){
                temp.push_back(matrix[i][j]);
            }
            matrix2.push_back(temp);
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                matrix[i][j]=matrix2[i][j];
            }
        }
    }


//INPLACE ROTATION - NOT EXTRA SPACE
    void rotate(vector<vector<int>>& matrix) {
        // TO TRANSPOSE THE MATRIX
        for(int i=0;i<matrix.size();i++){
            for(int j=i;j<matrix.size();j++){ //yaha j=0 se shuru mt krna
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        //SWAP COLUMNS
        int i=0,j=matrix.size()-1;
        while(i<j){
            for(int k=0;k<matrix.size();k++){
                swap(matrix[k][i],matrix[k][j]);
            }
            i++,j--;
        }
    }

// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[7,4,1],[8,5,2],[9,6,3]]