class Solution {
public:
    void BFS(unordered_map<int,vector<int>>&adj,vector<bool>&visit,int curr){
        visit[curr]=true;
        queue<int>que;
        que.push(curr);
        while(!que.empty()){
            int i=que.front();
            que.pop();
            for(auto it : adj[i]){
                if(!visit[it]){
                    visit[it]=true;
                    que.push(it);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int count=0;
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    //adj[j].push_back(i);
                }
            }
        }
        vector<bool>visit(n,false);
        for(int i=0;i<n;i++){
            if(!visit[i]){
                BFS(adj,visit,i);
                count++;
            }
        }
        return count;
    }
};