class Solution {
public:

    void backtrack(vector<int>& arr, int target ,int idx,vector<vector<int>>& ans,vector<int>& current){
        //Base case
        if(target==0){
            ans.push_back(current);
            return;
        }

        //Run loop for find the combination
        for(int i=idx;i<arr.size();i++){
            //check the arr is greater the target or not
            if(arr[i]>target) break;

            //Skip duplicate elements at the same decision level
            if(i>idx && arr[i]==arr[i-1]) continue;

            //Include the candidate
            current.push_back(arr[i]);

            // recall the backtracking function for the next index (each number used once) and reduced target
            backtrack(arr,target-arr[i],i+1,ans,current);
            // Backtrack

            current.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> current;
        sort(arr.begin(),arr.end());
        backtrack(arr,target,0,ans,current);
        return ans;
    }
};