//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int nthFibonacci(long long int n){
   int f[n + 2];
    int i;
    f[0] = 0;
    f[1] = 1;
 
    for(i = 2; i <= n; i++){
    
       f[i] = (f[i - 1] + f[i - 2])% 1000000007;
    }
    return f[n];

}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends