
class Solution {
public:
    bool increasingTriplet(std::vector<int>& nums) {
        int n = nums.size();
        if (n < 3) 
            return false;

        int small = nums[0];
        int big = INT_MAX;

        for (int i = 1; i < n; ++i) {
            if (nums[i] > big)
                return true;
            else if (nums[i] <= small) 
                small = nums[i];
            else if (nums[i] < big && nums[i] > small) 
                big = nums[i];
        }

        return false;
    }
};

