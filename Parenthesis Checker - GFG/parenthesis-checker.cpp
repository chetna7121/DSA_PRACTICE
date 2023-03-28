//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> sk;
        for(int i=0; i<x.length(); i++) {
            if(x[i]=='(' || x[i]=='{' || x[i]=='[') {
                sk.push(x[i]);
            } else if((!sk.empty()) && ((x[i]==')' && sk.top()=='(') || 
                      (x[i]=='}' && sk.top()=='{') || (x[i]==']' && sk.top()=='['))) {
                sk.pop();
            } else {
                return false;
            }
        }
        return sk.empty();
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends