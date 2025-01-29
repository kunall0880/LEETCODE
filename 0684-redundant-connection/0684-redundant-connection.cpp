class Solution {
public:
    bool dfs(unordered_map<int,vector<int>>&adj,int i,int j,vector<bool>&visit){
        visit[i]=true;
        if(i==j){
            return true;
        }
        for(auto it : adj[i]){
            if(!visit[it]){
                if(dfs(adj,it,j,visit)){
                    return true;
                }
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<n;i++){
            int u=edges[i][0],v=edges[i][1];
            vector<bool>visit(n,false);
            if(dfs(adj,u,v,visit)){
                return {u,v};
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
};