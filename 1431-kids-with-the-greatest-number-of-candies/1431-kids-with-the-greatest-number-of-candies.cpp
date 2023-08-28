class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
      
        vector<bool> result;
         int maxCandies = *max_element(candies.begin(), candies.end());
         for (int c : candies) {
        if (c + extraCandies >= maxCandies) {
            result.push_back(true);
        } else {
            result.push_back(false);
        }
    }
    return result;  
    }
};