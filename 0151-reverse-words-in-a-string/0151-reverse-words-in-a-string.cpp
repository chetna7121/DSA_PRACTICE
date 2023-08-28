class Solution {
public:
    string reverseWords(string s) {
      stringstream ss(s);
    vector<string> words;

    string word;
    while (ss >> word) {
        words.push_back(word);
    }
    reverse(words.begin(), words.end());
    string reversed_string = "";
    for (const string &w : words) {
        if (!reversed_string.empty()) {
            reversed_string += " ";
        }
        reversed_string += w;
    }
    return reversed_string;
}
};