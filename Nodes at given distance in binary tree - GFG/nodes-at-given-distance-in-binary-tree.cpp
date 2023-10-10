//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

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
    Node* root = newNode(stoi(ip[0]));
        
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
            currNode->left = newNode(stoi(currVal));
                
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
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:

public:
void mark_parent(Node*root,unordered_map<Node*,Node*>&parent_update){
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* current=q.front();
        q.pop();
        if(current->left){
            parent_update[current->left]=current;
            q.push(current->left);
        }
        if(current->right){
            parent_update[current->right]=current;
            q.push(current->right);
        }
    }
}

    vector <int> KDistanceNodes(Node* root, int key , int k)
    {
     Node*target;
     queue<Node*>extra;
     extra.push(root);
     while(!extra.empty()){
         Node*node=extra.front();extra.pop();
         if(node->data==key){
             target=node;
             break;
         }
         if(node->left){
             extra.push(node->left);

         }
         if(node->right){
             extra.push(node->right);
         }
     }
   
     unordered_map<Node*,Node*>parent_update;
        mark_parent(root,parent_update);
        unordered_map<Node*,bool>visited;
        queue<Node*>q;
        q.push(target);
        visited[target]=true;
        int distance=0;
        while(!q.empty()){
            int x=q.size();
          if(distance++==k){
              break;
          }
        while(x--){
              Node*current=q.front();q.pop();
              if(current->left&&!visited[current->left]){
                  visited[current->left]=true;
                  q.push(current->left);
              }
              if(current->right&&!visited[current->right]){
                  visited[current->right]=true;
                  q.push(current->right);
              }
              if(parent_update[current]&&!visited[parent_update[current]]){
                  visited[parent_update[current]]=true;;
                  q.push(parent_update[current]);
              }
          }
        }
        vector<int>result;
        while(!q.empty()){
         Node*current=q.front();q.pop();
         result.push_back(current->data);
        }
        sort(result.begin(),result.end());
        return result;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends