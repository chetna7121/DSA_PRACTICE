//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int maxProfit(int K, int N, int A[]) {
        if (N == 0 || K == 0) {
            return 0;
        }

        if (K >= N / 2) {
            int maxProfit = 0;
            for (int i = 1; i < N; i++) {
                if (A[i] > A[i - 1]) {
                    maxProfit += A[i] - A[i - 1];
                }
            }
            return maxProfit;
        }

        vector<vector<int>> dp(K + 1, vector<int>(N, 0));

        for (int i = 1; i <= K; i++) {
            int maxDiff = -A[0]; 
            for (int j = 1; j < N; j++) {
                dp[i][j] = max(dp[i][j - 1], A[j] + maxDiff);
                maxDiff = max(maxDiff, dp[i - 1][j] - A[j]);
            }
        }

        return dp[K][N - 1];
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends