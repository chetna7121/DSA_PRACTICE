//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution {
    int minEle;
    stack<int> s;
public:
    Solution() {
        minEle = -1;
    }
    int getMin() {
        if (s.empty()) {
            return -1;
        }
        return minEle;
    }
    int pop() {
        if (s.empty()) {
            return -1;
        }
        int popped = s.top();
        s.pop();
        if (popped == minEle) {
            if (s.empty()) {
                minEle = -1;
            }
            else {
                minEle = s.top();
                s.pop();
            }
        }
        return popped;
    }
    void push(int x) {
        if (s.empty() || x <= minEle) {
            s.push(minEle);
            minEle = x;
        }
        s.push(x);
    }


};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends