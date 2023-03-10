class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        bool found = binary_search(nums.begin(), nums.end(), target);
        if (found) {
            return distance(nums.begin(), lower_bound(nums.begin(), nums.end(), target));
        } else {
            int i = 0;
            while (i < nums.size() && target > nums[i]) {
                i++;
            }
            nums.insert(nums.begin() + i, target);
            return i;
        }
    }
};




