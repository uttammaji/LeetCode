class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128, 0);   
        vector<int> window(128, 0); 
        
        // Count how many unique characters we need
        int required = 0;
        for (char c : t) {
            if (need[c] == 0) {
                required++; 
            }
            need[c]++;
        }
        
        int have = 0;          // Unique characters currently satisfied
        int left = 0;          // Left pointer of our window
        int min_len = INT_MAX; // Length of the smallest window found
        int start_idx = 0;     // Starting index of the best window
        
        // Slide the right pointer across string s
        for (int right = 0; right < s.length(); right++) {
            char right_char = s[right];
            window[right_char]++;
            
            // If we hit the exact count needed for this character, increment 'have'
            if (need[right_char] > 0 && window[right_char] == need[right_char]) {
                have++;
            }
            
            // Shrink the window from the left as long as it's still valid
            while (have == required) {
                int current_window_len = right - left + 1;
                
                // Save if this window is smaller than what we found before
                if (current_window_len < min_len) {
                    min_len = current_window_len;
                    start_idx = left;
                }
                
                // Remove the left character from our window
                char left_char = s[left];
                window[left_char]--;
                
                // If removing this character breaks the requirements, decrement 'have'
                if (need[left_char] > 0 && window[left_char] < need[left_char]) {
                    have--;
                }
                
                left++; // Move left pointer forward
            }
        }
        
        // Return the smallest substring, or "" if no valid window exists
        return (min_len == INT_MAX) ? "" : s.substr(start_idx, min_len);
    }
};
