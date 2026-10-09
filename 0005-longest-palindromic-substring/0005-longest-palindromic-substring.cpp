class Solution {
private:
    int expandFromCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }

public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int start = 0, max_len = 0;
        
        for (int i = 0; i < s.length(); i++) {
            int len1 = expandFromCenter(s, i, i);
            int len2 = expandFromCenter(s, i, i + 1);
            int current_max = max(len1, len2);
            
            if (current_max > max_len) {
                max_len = current_max;
                start = i - (current_max - 1) / 2;
            }
        }
        
        return s.substr(start, max_len);
    }
};
