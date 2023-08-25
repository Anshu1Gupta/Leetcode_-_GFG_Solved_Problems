//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    public:
    int len=0;
    int find(Node*node,int key,int &sum){
        if(node==NULL)return 0;
        
        if(node->data==key){
            sum=len;
            return len;
            
        }
        
        // cout<<len<<endl;
        
        len++;
        find(node->left,key,sum);
        find(node->right,key,sum);
        len--;
        
        
        return len;
    }
    /* Should return minimum distance between a and b
    in a tree with given root*/
    Node*lca(Node*root,int a,int b){
        if(root==NULL||root->data==a||root->data==b)return root;
        
        Node*left=lca(root->left,a,b);
        Node*right=lca(root->right,a,b);
        
        if(left==NULL)return right;
        if(right==NULL)return left;
        return root;
    }
    int findDist(Node* root, int a, int b) {
        
        Node* comm=lca(root,a,b);
        // cout<<comm->data<<endl;
        len=0;
        int sum=0;
        int val1=find(comm,a,sum);
        val1=sum;
        len=0;
        sum=0;
        int val2=find(comm,b,sum);
        val2=sum;
        
        
        return val1+val2;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;
     
    }
    return 0;
}

// } Driver Code Ends