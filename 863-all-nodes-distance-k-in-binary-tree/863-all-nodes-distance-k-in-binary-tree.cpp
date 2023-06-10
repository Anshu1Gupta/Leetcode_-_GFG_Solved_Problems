/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void createParent(unordered_map<TreeNode*,TreeNode*>&parentof,TreeNode*root){
        parentof[root]=NULL;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode*parentNode=q.front();
            q.pop();
            if(parentNode->left){
                q.push(parentNode->left);
                parentof[parentNode->left]=parentNode;
            }
             if(parentNode->right){
                q.push(parentNode->right);
                parentof[parentNode->right]=parentNode;
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parentNode;
        createParent(parentNode,root);
        
        unordered_map<TreeNode*,int>visited;
        queue<pair<TreeNode*,int>>q;
       
        q.push({target,0});
        vector<int>ans;
        visited[target]=1;
        while(!q.empty()){
            TreeNode*node=q.front().first;
            int dist=q.front().second;
            if(dist==k)
                    ans.push_back(node->val);
            q.pop();
            cout<<node->val<<' '<<dist<<endl;
            if(node->left&&visited[node->left]==0){
                q.push({node->left,dist+1});
                visited[node->left]=1;
            }
            if(node->right&&visited[node->right]==0){
                q.push({node->right,dist+1});
                visited[node->right]=1;
            }
            if(parentNode[node]&&visited[parentNode[node]]==0){
                q.push({parentNode[node],dist+1});
                visited[parentNode[node]]=1;
            }
        }
        return ans;
        
        
    }
};