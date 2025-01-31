class Solution {
public:
    vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    int DFS(int i,int j,vector<vector<int>>&adj,int id){
        adj[i][j]=id;
        int count=1,n=adj.size();
        for(auto it : dir){
            int i_=i+it[0];
            int j_=j+it[1];
            if(i_>=0&&i_<n&&j_>=0&&j_<n&&adj[i_][j_]==1){
                count+=DFS(i_,j_,adj,id);
            }
        }
        return count;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int ans=0,maxi=0;
        unordered_map<int,int>unique;
        int uniqueid=2;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    unique[uniqueid]=DFS(i,j,grid,uniqueid);
                    uniqueid++;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    int ans=1;
                    unordered_set<int>st;
                    for(auto it : dir){
                        int i_=i+it[0];
                        int j_=j+it[1];
                        if(i_>=0&&i_<n&&j_>=0&&j_<n&&grid[i_][j_]!=0){
                            st.insert(grid[i_][j_]);
                        }
                    }
                    for(auto it: st){
                        ans+=unique[it];
                    }
                    maxi=max(maxi,ans);
                }
            }
        }
         if(maxi==0){
            return n*n;
        }
        return maxi;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(grid[i][j]==0){
        //             vector<vector<bool>>visit(n,vector<bool>(n,false));
        //             grid[i][j]=1;
        //             ans=DFS(i,j,grid,visit);
        //             maxi=max(maxi,ans);
        //             grid[i][j]=0;
        //         }
        //     }
        //
    }
};