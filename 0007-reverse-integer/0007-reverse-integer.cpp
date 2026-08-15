class Solution {
public:
    int reverse(int x) {
        int reverse_number=0;

        while(x!=0){
            int ld=x%10;
            if (reverse_number > INT_MAX / 10 || reverse_number < INT_MIN / 10) {
                return 0; 
            }
            reverse_number=(reverse_number*10)+ld;
            x=x/10;
        }

        return reverse_number;
    }
};