//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
  
string maxSum(string W, char X[], int B[], int N) {
    int n = W.size();
    unordered_map<char, int> map;
    for (int i = 0; i < N; i++) {
        map[X[i]] = B[i];
    }
    vector<int> val(n);
    for (int i = 0; i < n; i++) {
        char c = W[i];
        if (map.count(c)) {
            val[i] = map[c];
        } else {
            val[i] = (int)c;
        }
    }
    int max_sum = INT_MIN, curr_sum = 0;
    int start= -1, end = -1, curr_start = 0;
    for (int i = 0; i < n; i++) {
        curr_sum += val[i];
        if (curr_sum > max_sum) {
            max_sum = curr_sum;
            start = curr_start;
            end = i;
        }
        if (curr_sum < 0) {
            curr_sum = 0;
            curr_start = i + 1;
        }
    }
    return W.substr(start, end - start + 1);
}
};


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