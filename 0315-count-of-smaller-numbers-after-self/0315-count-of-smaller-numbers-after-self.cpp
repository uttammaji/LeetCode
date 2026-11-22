class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++) arr[i] = {nums[i], i};

        auto mergeSort = [&](auto& self, int l, int r) -> void {
            if (r - l <= 1) return;
            int m = l + (r - l) / 2;
            self(self, l, m);
            self(self, m, r);
            
            for (int i = l, j = m; i < m; i++) {
                while (j < r && arr[j].first < arr[i].first) j++;
                ans[arr[i].second] += j - m;
            }
            inplace_merge(arr.begin() + l, arr.begin() + m, arr.begin() + r);
        };

        mergeSort(mergeSort, 0, n);
        return ans;
    }
};
