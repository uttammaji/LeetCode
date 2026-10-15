class Solution {
public:
    void getAllCombination(vector<int>& arr, int idx, int target, vector<vector<int>>& ans, vector<int>& combination) {
        // Base Case 1: If target is met, we found a valid combination
        if (target == 0) {
            ans.push_back(combination);
            return;
        }
        
        // Base Case 2: Out of bounds or target exceeded
        if (idx == arr.size() || target < 0) {
            return;
        }

        // Choice 1: INCLUDE the current element
        // We stay at 'idx' because the same element can be reused
        combination.push_back(arr[idx]);
        getAllCombination(arr, idx, target - arr[idx], ans, combination);
        
        // Backtrack: Remove the element before trying the next choice
        combination.pop_back(); 

        // Choice 2: EXCLUDE the current element
        // We move to the next index 'idx + 1'
        getAllCombination(arr, idx + 1, target, ans, combination);
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> combination;
        getAllCombination(arr, 0, target, ans, combination);
        return ans;
    }
};
