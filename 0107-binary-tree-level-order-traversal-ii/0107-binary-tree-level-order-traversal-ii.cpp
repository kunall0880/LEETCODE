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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
       if(root==NULL){
        return {};
       } 
       queue<TreeNode *>que;
       que.push(root);
       vector<vector<int>>ans;
       while(!que.empty()){
        int N=que.size();
        vector<int>nums;
            while(N--){
                TreeNode * temp = que.front();
                nums.push_back(temp->val);
                que.pop();
                if(temp->left!=NULL){
                    que.push(temp->left);
                }
                if(temp->right!=NULL){
                    que.push(temp->right);
                }
            }
            ans.push_back(nums);
       }
       reverse(ans.begin(),ans.end());
       return ans;
    }
};