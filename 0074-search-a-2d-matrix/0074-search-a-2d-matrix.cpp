class Solution {
public:
    bool searchInRow(vector<vector<int>>& matrix, int target, int row){ //O(log n)
        int n=matrix[0].size();// search in a cloumn
        int st=0,end=n-1;

        while(st<=end){
            int mid=st+(end-st)/2;
            if(target==matrix[row][mid]){
                return true;
            }else if(target>matrix[row][mid]){
                st=mid+1;
            }else{
                end=mid-1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) { //O(log m)
        int m=matrix.size(),n=matrix[0].size();
        int stRow=0,endRow=m-1;
        while(stRow<=endRow){
            int midRow=stRow+(endRow-stRow)/2;
            if(target>=matrix[midRow][0] && target<=matrix[midRow][n-1]){
                return searchInRow(matrix,target,midRow);
            }else if(target>=matrix[midRow][n-1]){
                //down=> right
                stRow=midRow+1;
            }else{
                //up=>left
                endRow=midRow-1;
            }
        }
        return false;
    }
};