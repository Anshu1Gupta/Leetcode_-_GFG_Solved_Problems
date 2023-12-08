class Solution {
public:
    string tree2str(TreeNode* root) {
        stringstream ans;
        ans<<root->val;// has at least 1 node
        if (!root->right && !root->left) return ans.str();
        vector<TreeNode*> stack;// using vector as stack
        if (root->right) stack.push_back(root->right);
        if (root->left) stack.push_back(root->left);
        else ans<<"()";
        while(!stack.empty()){
            TreeNode* node=stack.back();
            stack.pop_back();
            if (!node) {
                ans<<')';
                continue;
            }
            ans<<'('<<node->val;
            TreeNode* left=node->left, *right=node->right;
            if (!left && !right) {
                ans<<')';
                continue;
            }
            stack.push_back(NULL);
            if (right) stack.push_back(right);
            if (left) stack.push_back(left);
            else ans<<"()";
        }
        return ans.str();
    }
};
