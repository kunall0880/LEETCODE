class Solution {
public:
    int n;
    TreeNode*solve(string & str,int & i,int dep){
        if(i>=n){
            return NULL;
        }
        int j=i;
        while(j<n && str[j]=='-'){
            j++;
        }
        int dash=j-i;
        if(dash!=dep){
            return NULL;
        }
        int num=0;
        i+=dash;
        while(i<n && isdigit(str[i])){
            num=(num*10)+(str[i]-'0');
            i++;
        }
        TreeNode * root = new TreeNode(num);
        root->left=solve(str,i,dep+1);
        root->right=solve(str,i,dep+1);
        return root;
    }
    TreeNode* recoverFromPreorder(string str) {
        int i=0,depth=0;
        n=str.length();
       return solve(str,i,0);
    }
};