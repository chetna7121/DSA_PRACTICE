//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
          stack<int> sk;
       for(int i=0;i<S.length();i++)
       {
           if(isdigit(S[i]))
           {
             sk.push(S[i] - '0');   
           }
          else 
          {
              int a=sk.top();
              sk.pop();
              int b= sk.top();
              sk.pop();
              switch (S[i]) {
            case '+':
                sk.push(b + a);
                break;
            case '-':
                sk.push(b - a);
                break;
            case '*':
                sk.push(b * a);
                break;
            case '/':
                sk.push(b / a);
                break;
            }
          }
       }
       return sk.top();
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends