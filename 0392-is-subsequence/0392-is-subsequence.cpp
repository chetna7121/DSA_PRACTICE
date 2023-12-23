class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        int first = 0; 
        int second = 0;  

        while (first < s.length() && second < t.length()) {
            if (s[first] != t[second]) {
                second++;
            } else if (s[first] == t[second]) {
                first++;
                second++;
            }
        }

        return first == s.length();
    }
};