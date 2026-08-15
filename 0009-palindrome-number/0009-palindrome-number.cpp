class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        long rn = 0;
        int dupl = x;

        while (x > 0) {
            int ld = x % 10;
            rn = (rn * 10) + ld;
            x = x / 10;
        }
        return dupl == rn;
    }
};
