class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      // another approch called slow-fast pointer approch // use this approuch becase previous approch take space complexito O(n)  but this approch take O(1)
      int slow=nums[0],fast=nums[0];
      do{
        slow=nums[slow];//+1
        fast=nums[nums[fast]];//+2

      }while(slow!=fast);

      slow=nums[0];

      while(slow!=fast){
        slow=nums[slow];//+1
        fast=nums[fast];//+1
      }
      return slow;

    }
};