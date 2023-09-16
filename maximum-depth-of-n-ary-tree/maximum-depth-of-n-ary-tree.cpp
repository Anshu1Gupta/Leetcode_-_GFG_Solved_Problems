/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void findHeight(Node*root,int &maxi,int ind){
        if(root==NULL)return;
        int size=root->children.size();
        maxi=max(maxi,ind);
        for(int i=0;i<size;i++){
            findHeight(root->children[i],maxi,ind+1);
        }
    }
    int maxDepth(Node* root) {
     int maxi=0;
        if(root==NULL)return 0;
        
        findHeight(root,maxi,0);
        return maxi+1;
    }
};