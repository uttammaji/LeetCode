class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m; // stores {element, nextGreaterElement}
        stack<int> s;

        // Step 1: Traverse nums2 from right to left to find Next Greater for all elements
        for (int i = nums2.size() - 1; i >= 0; i--) {
            // Pop all elements smaller than or equal to current element
            while (s.size() > 0 && s.top() <= nums2[i]) {
                s.pop();
            }

            // If stack is empty, no greater element exists on the right
            if (s.empty()) {
                m[nums2[i]] = -1;
            } else {
                m[nums2[i]] = s.top();
            }

            // Push current element into stack
            s.push(nums2[i]);
        }

        // Step 2: Build the answer for nums1 using the map
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            ans.push_back(m[nums1[i]]);
        }

        return ans;
    }
};
