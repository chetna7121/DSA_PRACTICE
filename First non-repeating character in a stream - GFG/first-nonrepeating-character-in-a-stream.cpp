//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
    int count[52] = {0};  
    queue<char> q;        
    string result = "";   
    for (char c : A) {   
        q.push(c);       
        count[c-'a']++;   
        while (!q.empty() && count[q.front()-'a'] > 1) {
            q.pop();  
        }
        if (q.empty()) {
            result += "#"; 
        } else {
            result += q.front(); 
        }
    }
    return result; 
}


};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends