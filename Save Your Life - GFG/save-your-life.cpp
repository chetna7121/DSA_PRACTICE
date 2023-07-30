//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution {
public:
    string maxSum(string w, char x[], int b[], int n) {
        std::unordered_map<char, int> map;
        for (int i = 0; i < n; i++) {
            map[x[i]] = b[i];
        }
        int maxsum = INT_MIN, currsum = 0;
        std::string s = "", temp = "";

        for (int i = 0; i < w.size(); i++) {
            int ascii;
            if (map.find(w[i]) != map.end()) {
                ascii = map[w[i]];
            } else {
                ascii = (int) w[i];
            }

            currsum += ascii;
            temp += w[i];
            if (maxsum < currsum) { 
                maxsum = currsum;
                s = temp;
            }
            if (currsum < 0) {  
                currsum = 0;
                temp = "";
            }
        }

        return s; 
    }
};

          // Create a dictionary to store redefined ascii alues
       /* unordered_map<char, int> ascii_dict;
        for (int i = 0; i < n; i++) {
            ascii_dict[x[i]] = b[i];
        }
        int maxsum = 0;
        std::string max_substring;

        // Brute force approach
         for (int i = 0; i < w.size(); i++) {
            for (int j = i; j < w.size(); j++) {
                int sum = 0;
                for (int k = i; k <= j; k++) {
                    sum += ascii_dict[w[k]];
                }
                if (sum > maxsum) {
                    maxsum = sum;
                    max_substring = w.substr(i, j - i + 1);
                }
            }
        }
        return max_substring;
    }*/


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends