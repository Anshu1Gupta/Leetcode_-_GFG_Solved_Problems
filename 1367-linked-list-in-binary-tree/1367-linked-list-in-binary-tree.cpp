/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    // bool isSubPath(ListNode* head, TreeNode* root) {
        
  bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false;  // If the tree is empty, there can't be a path

        // Check if current root matches or recursively check in left or right subtree
        if (dfs(head, root)) return true;

        // Recursively check in left and right subtrees
        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }

private:
    // Helper function to perform DFS and check if linked list is a path in the tree
    bool dfs(ListNode* head, TreeNode* root) {
        if (!head) return true;  // All nodes in the linked list have been matched
        if (!root) return false;  // Reached the end of the tree path without matching all nodes

        // If the current values match, continue to check left and right subtrees
        if (head->val != root->val) return false;

        // Recursively check the next node in the linked list with left and right children of the tree
        return dfs(head->next, root->left) || dfs(head->next, root->right);
    }
};