class Solution {
public:
    vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    int DFS(int i,int j,vector<vector<int>>&adj,vector<vector<bool>>&visit,int id){
        visit[i][j]=true;
        adj[i][j]=id;
        int count=1,n=adj.size();
        for(auto it : dir){
            int i_=i+it[0];
            int j_=j+it[1];
            if(i_>=0&&i_<n&&j_>=0&&j_<n&&visit[i_][j_]==false&&adj[i_][j_]==1){
                count+=DFS(i_,j_,adj,visit,id);
            }
        }
        return count;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int ans=0,maxi=0;
        unordered_map<int,int>unique;
        vector<vector<bool>>visit(n,vector<bool>(n,false));
        int uniqueid=2;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1&&visit[i][j]==false){
                    unique[uniqueid]=DFS(i,j,grid,visit,uniqueid);
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