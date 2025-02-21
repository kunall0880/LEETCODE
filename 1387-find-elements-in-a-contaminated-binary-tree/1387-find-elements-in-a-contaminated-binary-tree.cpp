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
class FindElements {
public:
    unordered_set<int>st;
    void BFS(TreeNode * root){
        queue<TreeNode*>que;
        que.push(root);
        root->val=0;
        int x=0;
        while(!que.empty()){
            TreeNode * temp=que.front();
            que.pop();
            x=temp->val;
            st.insert(x);
            if(temp->right!=NULL){
                temp->right->val=2*x+2;
                que.push(temp->right);
            }
            if(temp->left){
                temp->left->val=x*2+1;
                que.push(temp->left);
            }
        }
    }
    TreeNode * main;
    FindElements(TreeNode* root) {
        main=root;
        BFS(root);
    }
    
    bool find(int target) {
       return st.find(target)!=st.end();
    }
};
// bool BFSser(TreeNode * root,int ele){
//         queue<TreeNode*>que;
//         que.push(root);
//         while(!que.empty()){
//             TreeNode * temp=que.front();
//             que.pop();
//             int x=temp->val;
//             if(x==ele){
//                 return true;
//             }
//             if(temp->right!=NULL){
//                 que.push(temp->right);
//             }
//             if(temp->left){
//                 que.push(temp->left);
//             }
//         }
//         return false;
//     }

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */