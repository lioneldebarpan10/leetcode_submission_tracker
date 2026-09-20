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
    // Efficient way to find LCA in BST
    // Time Complexity -> O(h)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root != NULL){
            if(p->val < root->val && q->val < root->val){
                root = root->left; // both node lies in left subtrees
            }
            else if(p->val > root->val && q->val > root->val){
                root = root->right; // both node lies in right subtrees
            }
            else{
                // node splitting happens here , Root is the LCA
                return root;
            }
        }
        return NULL;   
    }
};