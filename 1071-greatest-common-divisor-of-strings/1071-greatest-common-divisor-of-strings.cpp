class Solution {
public:
   string gcdOfStrings(string str1, string str2) {
 int len1 = str1.length();
    int len2 = str2.length();
    int gcd_len = __gcd(len1, len2); 
    string potential_answer = str1.substr(0, gcd_len);

    if (str1 + str2 == str2 + str1) {
        return potential_answer;
    }

    return "";
   }
};