/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root==NULL){
            return {};
        }
        vector<vector<int>>ans;
        queue<Node*>que;
        que.push(root);
        while(!que.empty()){
            int N=que.size();
            vector<int>nums;
            while(N--){
                Node * temp=que.front();
                nums.push_back(temp->val);
                que.pop();
                for(auto it : temp->children){
                    que.push(it);
                }
            }
            ans.push_back(nums);
        }
        return ans;
    }
};