class Solution {
public:
    void BFS(unordered_map<int,vector<int>>&adj,int start,vector<bool>&visit,int &c1,int&c2){
        queue<int>que;
        que.push(start);
        visit[start]=true;
        while(!que.empty()){
            int node=que.front();
            que.pop();
            for(auto it :adj[node]){
                if(!visit[it]){
                    que.push(it);
                    visit[it]=true;
                }
                c2++;
            }
            c1++;
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        for(auto it : edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int res=0;
        vector<bool>visit(n+1,false);
        for(int i=0;i<n;i++){
            if(!visit[i]){
                int count1=0,count2=0;
                BFS(adj,i,visit,count1,count2);
                if((count1*(count1-1))==count2){
                    res++;
                }
            }
        }
        return res;
    }
};