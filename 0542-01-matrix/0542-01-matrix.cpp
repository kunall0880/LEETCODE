class Solution {
public:
    typedef pair<int,int>P;
    vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        
        queue<P>qu;
        vector<vector<int>>ans(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    qu.push({i,j});
                    ans[i][j]=0;
                }
            }
        }

        while(!qu.empty()){
            int N=qu.size();
            while(N--){
                P curr=qu.front();
                qu.pop();
                int i=curr.first;
                int j=curr.second;
                for(auto it : dir){
                    int i_ = i+it[0];
                    int j_ = j+it[1];
                    if(i_>=0 && i_<m && j_>=0 && j_ <n && ans[i_][j_]==-1){
                        ans[i_][j_]=ans[i][j]+1;
                        qu.push({i_,j_});
                    }
                }
            }
        }
        return ans;
    }
};