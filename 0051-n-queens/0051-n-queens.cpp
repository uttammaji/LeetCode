class Solution {
public:

    bool issafe(vector<string>& board,int row,int col,int n){
        //For horizontal
        for(int j=0;j<n;j++){
            if(board[row][j]=='Q'){
                return false;
            }
        }

        //For Vertical
        for(int i=0;i<n;i++){
            if(board[i][col]=='Q'){
                return false;
            }
        }

        //For left Diagonal
        for(int i=row,j=col;i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q'){
                return false;
            }
        }

        //For Right Diagonal
        for(int i=row,j=col;i>=0 && j<n;i--,j++){
            if(board[i][j]=='Q'){
                return false;
            }
        }

        return true;
    }

    void nQueens(vector<string>& board,int row,int n,vector<vector<string>>& ans){
        if(row==n){
            ans.push_back({board});
            return;
        }

        for(int j=0;j<n;j++){
            if(issafe(board,row,j,n)){
                board[row][j]='Q'; //in safe place put the q 
                nQueens(board,row+1,n,ans);
                board[row][j]='.'; //where queen put is not possible there put the dot 
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        vector<vector<string>> ans;
        nQueens(board,0,n,ans);
        return ans;
    }
};