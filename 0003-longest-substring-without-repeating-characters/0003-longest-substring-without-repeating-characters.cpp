class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> ump;
        int left = 0, max_len = 0;
        for (int right = 0; right < n; right++) {
            char c = s[right];
            if (ump.find(c) != ump.end() && ump[c] >= left) {
                left = ump[c] + 1;
            }
            ump[c] = right;
            int len = right - left + 1;
            if (len > max_len) {
                max_len = len;
            }
        }
        return max_len;
    }
};
