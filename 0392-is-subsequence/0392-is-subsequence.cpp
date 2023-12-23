class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        int first = 0; 
        int second = 0;  

        while (second < t.length()) {
            if (s[first] != t[second]) {
                second++;
            } else if (s[first] == t[second]) {
                first++;
                second++;
            }
        }

 if (first == s.length()) {
            return true;
        } else {
            return false;
        }
    }
};