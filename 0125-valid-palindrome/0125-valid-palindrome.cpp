
class Solution {
public:
    bool isPalindrome(std::string s) {
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            // Move left pointer forward if the character is not alphanumeric
            if (!std::isalnum(s[left])) {
                left++;
            } 
            // Move right pointer backward if the character is not alphanumeric
            else if (!std::isalnum(s[right])) {
                right--;
            } 
            // If both are alphanumeric, compare them in lowercase
            else {
                if (std::tolower(s[left]) != std::tolower(s[right])) {
                    return false;
                }
                left++;
                right--;
            }
        }
        
        return true;
    }
};
