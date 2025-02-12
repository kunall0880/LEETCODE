/*
 *
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL){
            return {};
        }
      vector<vector<int>>ans;
      queue<TreeNode *>que;
      que.push(root);
      int count=0;
      while(!que.empty()){
        int N=que.size();
        vector<int>nums;
        while(N--){
            TreeNode * temp=que.front();
            nums.push_back(temp->val);
            que.pop();
            if(temp->right!=NULL){
                que.push(temp->right);
            }
            if(temp->left!=NULL){
                que.push(temp->left);
            }
        }
        if(count%2==0){
            reverse(nums.begin(),nums.end());
        }
        ans.push_back(nums);
        count++;
      }  
      return ans;
    }
};