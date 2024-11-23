class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<char>>ans(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j]=matrix[j][i];
            }
        }
        for(auto & it : ans){
            reverse(it.begin(),it.end());
        }
        for(int j=0;j<m;j++){
            int lastspace=n-1;
            for(int i=n-1;i>=0;i--){
                if(ans[i][j]=='*'){
                    lastspace=i-1;
                }else if(ans[i][j]=='#'){
                    ans[i][j]='.';
                    ans[lastspace][j]='#';
                    lastspace--;
                }
            }
        }
        return ans;
    }
};