class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int V=adj.size();
        vector<vector<int>>graph(V);
        vector<int>indegree(V,0);
        for(int u=0;u<V;u++){
            for(auto it : adj[u]){
                graph[it].push_back(u);
                indegree[u]++;
            }
        }
        queue<int>que;
        vector<bool>safe(V,false);
        for(int it=0;it<V;it++){
            if(indegree[it]==0){
                que.push(it);
            }
        }
        while(!que.empty()){
            int u=que.front();
            que.pop();
            safe[u]=true;
            for(auto it : graph[u]){
                indegree[it]--;
                if(indegree[it]==0){
                    que.push(it);
                }
            }
        }
        vector<int>ans;
        for(int i=0;i<V;i++){
            if(safe[i]==true){
                ans.push_back(i);
            }
        }
        return ans;
    }
};