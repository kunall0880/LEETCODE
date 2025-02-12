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
    vector<int> BFS(TreeNode* root){
        vector<int>ans;
        queue<pair<TreeNode*,int>>qu;
        qu.push({root,0});
        ans.push_back(root->val);
        int curr=0;
        while(!qu.empty()){
            TreeNode * temp=qu.front().first;
            int lev=qu.front().second;
            qu.pop();
            if(curr<lev){
                ans.push_back(temp->val);
                curr=lev;
            }
            if(temp->right!=NULL){
                qu.push({temp->right,lev+1});
            }
            if(temp->left!=NULL){
                qu.push({temp->left,lev+1});
            }
        }
        return ans;
    }
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        return BFS(root);
    }
};