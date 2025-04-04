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
    unordered_map<int,int>mp;
    int maxdep=0;
    TreeNode* LCA(TreeNode* root){
        if(root==NULL || mp[root->val]==maxdep){
            return root;
        }
        TreeNode* l = LCA(root->left);
        TreeNode* r = LCA(root->right);
        if(l&&r){
            return root;
        }
        return l?l:r;
    }
    void depth(int deap,TreeNode * root){
            if(!root){
                return ;
            }
            maxdep=max(maxdep,deap);
            mp[root->val]=deap;
            depth(deap+1,root->left);
            depth(deap+1,root->right);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        depth(0,root);

        return LCA(root);
    }
};