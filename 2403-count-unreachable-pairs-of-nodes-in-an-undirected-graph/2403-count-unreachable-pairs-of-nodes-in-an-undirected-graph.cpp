class Solution {
public:
    void dfs(int i,unordered_map<int,vector<int>>&adj,vector<bool>&visit,long long &size){
        visit[i]=true;
        size=size+1;
        for(auto it : adj[i]){
            if(!visit[it]){
                dfs(it,adj,visit,size);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& grid) {
        int m=grid.size(),l=grid.size();
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<grid.size();i++){
            int u=grid[i][0];
            int v=grid[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        long long count=0;
        long long w=n;
        vector<bool>visit(n,false);
        for(int i=0;i<n;i++){
            long long size=0;
            if(!visit[i]){
            dfs(i,adj,visit,size);
            count=count+(size*(w-size));
            w=w-size;
            }
        }
        return count;
    }
};