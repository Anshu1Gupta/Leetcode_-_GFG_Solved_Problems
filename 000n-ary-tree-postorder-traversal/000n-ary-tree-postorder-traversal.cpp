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
    void postOrder(Node*root,vector<int>&ans){
        if(root==NULL)return;
        int size=root->children.size();
        for(int i=0;i<size;i++){
            postOrder(root->children[i],ans);
        }
        ans.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        vector<int>ans;
        postOrder(root,ans);
        return ans;
    }
};