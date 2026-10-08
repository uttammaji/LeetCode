class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {  // This is burthforce approch
       int n=nums.size();
       int count=0;
       for(int i=0;i<n;i++){//starting 
         int sum=0;
         for(int j=i;j<n;j++){//ending
            sum +=nums[j];
            if(sum==k) count++;
        }
       } 
     return count;
    }
};