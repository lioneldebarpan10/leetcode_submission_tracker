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
    bool isValidBST(TreeNode* root) {
        return isvalidiate(root , LONG_MIN , LONG_MAX);
      
    }
    bool isvalidiate(TreeNode* node , long minValue , long maxValue){
        if(node == NULL) return true;
        if(node->val <= minValue || node->val >= maxValue){
            return false;
        }
        return isvalidiate(node->left , minValue , node->val) &&
        isvalidiate(node->right , node->val , maxValue);
    }
};