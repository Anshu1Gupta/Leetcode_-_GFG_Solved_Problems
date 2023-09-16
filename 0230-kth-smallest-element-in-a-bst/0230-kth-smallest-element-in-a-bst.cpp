/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        // int size=morisTraversal(root);
        
        TreeNode*curr=root;
        int ans=-1;
        int count=0;
        while(curr!=NULL){
            if(curr->left){
                TreeNode*temp=curr->left;
                while(temp->right!=NULL&&temp->right!=curr)temp=temp->right;
                
                if(temp->right==NULL){
                    temp->right=curr;
                    curr=curr->left;
                }
                else{
                    temp->right=NULL;
                    cout<<curr->val<<endl;
                    count++;
                    if(count==k){
                        ans=curr->val;
                    }
                    // k--;
                    // if(k==0)return curr->val;
                    curr=curr->right;
                }
                
            }
            else{
                count++;
                if(count==k){
                    ans=curr->val;
                }
                // k--;
                // if(k==0)ans=curr->val;
                cout<<curr->val<<endl;
                curr=curr->right;
            }
        }
        
        
        return ans;
    }
};