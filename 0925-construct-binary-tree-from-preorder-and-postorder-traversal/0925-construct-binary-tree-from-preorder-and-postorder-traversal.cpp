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
    TreeNode* solve(int prestart,int poststart,int preend,vector<int>&pre,vector<int>&post){
        if(prestart>preend){
            return NULL;
        }
        TreeNode* root=new TreeNode(pre[prestart]);
        if(prestart==preend){
            return root;
        }
        int next=pre[prestart+1];

        int j=poststart;
        while(post[j]!=next){
            j++;
        }
        int num=j-poststart+1;

        root->left=solve(prestart+1,poststart,prestart+num,pre,post);
        root->right=solve(prestart+num+1,j+1,preend,pre,post);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n=preorder.size();
        return solve(0,0,n-1,preorder,postorder);
    }
};