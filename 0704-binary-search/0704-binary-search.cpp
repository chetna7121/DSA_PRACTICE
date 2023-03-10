class Solution {
public:
    int search(vector<int>& nums, int target) {
        bool x = binary_search(nums.begin(), nums.end(), target);
        if(x) {
            return distance(nums.begin(), lower_bound(nums.begin(), nums.end(), target));
        } else {
            return -1;
        }
    }
};