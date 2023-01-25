// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution
{
public:
    string longestString(vector<string> &a)
    {
        sort(a.begin(),a.end());
        unordered_map<string,int>ump;
        int n=a.size();
        string ans;
        for(int i=0;i<n;i++){
            ump[a[i]]++;
        }
        for(int i=0;i<n;i++){
            int sz=a[i].size();
            string s;
            for(int j=0;j<sz;j++){
                s+=a[i][j];
                if(!ump[s]){
                    sz=0;
                    break;
                }
            }
            if(ans.size()<sz){
            ans=a[i];
            }
        }
        return ans;
    }
};
// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> v(n);
        for(int i = 0; i < n ; i++)
        {
            cin>>v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends


