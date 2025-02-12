/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void BFS(Node * root){
        queue<pair<Node*, int>>que;
        que.push({root,0});
        root->next=NULL;
        int curr=1;
        while(!que.empty()){
            int N=que.size();
            Node * temp;
            while(N--){
                temp=que.front().first;
                int lev=que.front().second;
                que.pop();
                if(temp->left!=NULL){
                    que.push({temp->left,lev+1});
                }
                if(temp->right!=NULL){
                    que.push({temp->right,lev+1});
                }
                temp->next=que.front().first;
            }
            cout<<endl;
            temp->next=NULL;
        }
    }
    Node* connect(Node* root) {
        if(root==NULL){
            return root;
        }
        BFS(root);
        return root;
    }
};