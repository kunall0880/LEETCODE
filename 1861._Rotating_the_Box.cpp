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
            for(int i=n-1;i>=0;i--){
                if(ans[i][j]=='.'){
                    int stonerow=-1;
                    for(int k=i-1;k>=0;k--){
                        if(ans[k][j]=='*'){
                            break;
                        }else if(ans[k][j]=='#'){
                            stonerow=k;
                            break;
                        }
                    }
                    if(stonerow!=-1){
                        ans[i][j]='#';
                        ans[stonerow][j]='.';
                    }
                }
            }
        }
        return ans;
    }
};