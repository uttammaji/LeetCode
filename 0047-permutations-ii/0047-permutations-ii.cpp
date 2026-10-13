class Solution {
public:

    void backTrack(vector<int>& nums,vector<vector<int>>& result,vector<bool>& used,vector<int>& currentPath){
        if(currentPath.size() == nums.size()){
            result.push_back(currentPath);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(used[i]==true){
                continue;
            }

            if(i>0 && nums[i]==nums[i-1] && !used[i-1]){
                continue;
            }

            used[i]=true;
            currentPath.push_back(nums[i]);
            backTrack(nums,result,used,currentPath);
            currentPath.pop_back();//backtracing
            used[i]=false;
        }

    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        vector<int> currentPath;
        vector<bool> used(nums.size(), false);
        backTrack(nums,result,used,currentPath);
        return result;
    }
};