class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int CurrArray=0;
        int maxSub=INT_MIN;

        for(int val:nums){
            CurrArray +=val;
            maxSub=max(CurrArray,maxSub);

            if(CurrArray<0){
                CurrArray=0;
            }
        }
        return maxSub;
        
    }
};