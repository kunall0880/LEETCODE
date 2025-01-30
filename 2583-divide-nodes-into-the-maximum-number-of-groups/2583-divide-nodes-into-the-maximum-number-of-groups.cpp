class Solution {
public:
    bool isbipart(unordered_map<int, vector<int>> &adj,vector<int>&colors,int curr,int currCol){
        colors[curr]=currCol;
        for(auto it : adj[curr]){
            if(colors[it] == colors[curr]){
                return false;
            }
            if(colors[it]==-1){
                if(isbipart(adj,colors,it,1-currCol)==false){
                    return false;
                }
            }
        }
        return true;
    }

    int bfs(unordered_map<int, vector<int>>& adj,int curr,int n){
        vector<bool>visit(n,false);
        queue<int>que;
        que.push(curr);
        visit[curr]=true;
        int level=1;
        while(!que.empty()){
            int N=que.size();
            while(N--){
                int i=que.front();
                que.pop();

                for(auto it: adj[i]){
                    if(!visit[it]){
                        que.push(it);
                        visit[it]=true;
                    }
                }
            }
            level++;
        }
        return level-1;
    }
    int dfs(unordered_map<int,vector<int>>&adj,int curr,vector<bool>&visit,vector<int>&level){
        visit[curr]=true;
        int maxi=level[curr];
        for(auto it:adj[curr]){
            if(!visit[it]){
                maxi=max(maxi,dfs(adj,it,visit,level));
            }
        }
        return maxi;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        for(auto it : edges){
            int u=it[0]-1;
            int v=it[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>colour(n,-1);
        for(int i=0;i<n;i++){
            if(colour[i]==-1){
                if(isbipart(adj,colour,i,1)==false){
                    return -1;
                }
            }
        }

        vector<int>count(n,0);
        for(int i=0;i<n;i++){
            count[i]=bfs(adj,i,n);
        }

        int ans=0;
        vector<bool>visit(n,false);
        for(int i=0;i<n;i++){
            if(!visit[i]){
                ans+=dfs(adj,i,visit,count);
            }
        }
        return ans;
    }
};