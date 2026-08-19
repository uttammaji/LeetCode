class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int left = 0;
        int right = height.size() - 1;
        
        while (left < right) {
            // Calculate current width and height
            int width = right - left;
            int currentHeight = min(height[left], height[right]);
            
            // Update the maximum water area found so far
            int area = width * currentHeight;
            maxWater = max(maxWater, area);
            
            // Move the pointer that points to the shorter line
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return maxWater;
    }
};
