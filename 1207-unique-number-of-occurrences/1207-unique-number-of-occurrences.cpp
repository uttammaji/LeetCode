class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
       unordered_map<int, int> counts; 
       unordered_set<int> unique_counts;

       for(int num:arr){
        counts[num]++;
       }

       for(auto pair:counts){
        int frequency=pair.second;
        if(unique_counts.count(frequency)){
            return false;
        }
        unique_counts.insert(frequency);
       }
       return true;
    }   
};