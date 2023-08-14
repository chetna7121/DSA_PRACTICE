//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};





// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}



// } Driver Code Ends
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution
{
public:
 void inorderTraversal(Node *root, vector<int> &result)
    {
        if (root)
        {
            inorderTraversal(root->left, result);
            result.push_back(root->data);
            inorderTraversal(root->right, result);
        }
    }

    vector<int> merge(Node *root1, Node *root2)
    {
        vector<int> result;

        stack<Node *> s1, s2;
        Node *current1 = root1, *current2 = root2;

        while (current1 || current2 || !s1.empty() || !s2.empty())
        {
            while (current1)
            {
                s1.push(current1);
                current1 = current1->left;
            }

            while (current2)
            {
                s2.push(current2);
                current2 = current2->left;
            }

            if (!s1.empty() && (s2.empty() || s1.top()->data <= s2.top()->data))
            {
                current1 = s1.top();
                s1.pop();
                result.push_back(current1->data);
                current1 = current1->right;
            }
            else if (!s2.empty())
            {
                current2 = s2.top();
                s2.pop();
                result.push_back(current2->data);
                current2 = current2->right;
            }
        }

        return result;
    }
};

/*
    void inorderTraversal(Node *root, vector<int> &result)
    {
        if (root)
        {
            inorderTraversal(root->left, result);
            result.push_back(root->data);
            inorderTraversal(root->right, result);
        }
    }

    vector<int> merge(Node *root1, Node *root2)
    {
        vector<int> result;
        vector<int> elements1, elements2;

        inorderTraversal(root1, elements1);
        inorderTraversal(root2, elements2);

        int i = 0, j = 0;
        while (i < elements1.size() && j < elements2.size())
        {
            if (elements1[i] < elements2[j])
                result.push_back(elements1[i++]);
            else
                result.push_back(elements2[j++]);
        }

        while (i < elements1.size())
            result.push_back(elements1[i++]);

        while (j < elements2.size())
            result.push_back(elements2[j++]);

        return result;
    }
};
*/




//{ Driver Code Starts.
int main() {

   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       getline(cin, s);
       Node* root2 = buildTree(s);
    
       // getline(cin, s);
       Solution obj;
       vector<int> vec = obj.merge(root1, root2);
       for(int i=0;i<vec.size();i++)
            cout << vec[i] << " ";
        cout << endl;
       ///cout<<"~"<<endl;
   }
   return 0;
}
// } Driver Code Ends