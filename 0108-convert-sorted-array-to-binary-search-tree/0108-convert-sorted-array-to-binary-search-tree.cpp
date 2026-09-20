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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildTree(nums , 0 , nums.size() - 1); // call function from 0 to n-1
    }
    TreeNode* buildTree(vector<int>& nums , int left , int right){
        if(left > right) return NULL; 
        int mid = left + (right - left) / 2; // middle of array
        TreeNode* node = new TreeNode(nums[mid]); // nums[mid] is the root of BST
        node->left = buildTree(nums , left , mid - 1); // recursively traverse left subtree
        // from 0 to mid-1
        node->right = buildTree(nums , mid + 1 , right); //recursively traverse right subtree
        // from mid + 1 to right
        return node;
    }
};