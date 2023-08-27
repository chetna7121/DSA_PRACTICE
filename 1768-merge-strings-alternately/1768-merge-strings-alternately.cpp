class Solution {
public:
  string mergeAlternately(string word1, string word2) {
        string output = "";
        int n = min(word1.size(), word2.size());

        for (int i = 0; i < n; i++) {
            output += word1[i];
            output += word2[i];
        }

        output += word1.substr(n) + word2.substr(n);
        return output;
    }
};
