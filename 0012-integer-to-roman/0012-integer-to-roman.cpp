class Solution {
public:
    string intToRoman(int num) {
        // Pair values with their corresponding Roman numeral symbols
        // Including both standard and subtractive forms in descending order
        const vector<pair<int, string>> valueMap = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"},  {90, "XC"},  {50, "L"},  {40, "XL"},
            {10, "X"},   {9, "IX"},   {5, "V"},   {4, "IV"},
            {1, "I"}
        };
        
        string romanResult = "";
        
        // Loop through the map and greedily append the largest possible values
        for (const auto& [value, symbol] : valueMap) {
            if (num == 0) break;
            
            int count = num / value;
            if (count > 0) {
                for (int i = 0; i < count; ++i) {
                    romanResult += symbol;
                }
                num %= value;
            }
        }
        
        return romanResult;
    }
};
