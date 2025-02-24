class Solution {
public:
    bool DFS(unordered_map<int,vector<int>>&adj,int curr,unordered_map<int,int>&time,vector<bool>&visit,int t){
        visit[curr]=true;
        time[curr]=t;

        if(curr==0){
            return true;
        }
        for(auto & it : adj[curr]){
            if(!visit[it]){
                if(DFS(adj,it,time,visit,t+1)==true){
                    return true;
                }
            }
        }
        time.erase(curr);
        return false;
    }
    
    int BFSa(unordered_map<int,vector<int>>&adj,unordered_map<int,int>&bob,vector<bool>&visit,vector<int>&nums){
        int ans=INT_MIN;
        queue<vector<int>>que;
        que.push({0,0,0});
        while(!que.empty()){
            int node=que.front()[0];
            int time=que.front()[1];
            int income=que.front()[2];
            que.pop();
            if(bob.find(node)==bob.end()||time<bob[node]){
                income+=nums[node];
            }else if(bob[node]==time){
                income+=(nums[node]/2);
            }else{
                income+=0;
            }
            if(adj[node].size()==1 && node !=0){
                ans=max(ans,income);
            }
            for(auto it : adj[node]){
                if(visit[it]==false){
                    que.push({it,time+1,income});
                }
            }
            visit[node]=true;
        }
        return ans;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        unordered_map<int,vector<int>>adj;
        unordered_map<int,int>bobmp;
        int n=edges.size();
        for(int i=0;i<n;i++){
            int u=edges[i][0],v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>visit(amount.size(),false);
        DFS(adj,bob,bobmp,visit,0);
        vector<bool>visited(amount.size(),false);
        return BFSa(adj,bobmp,visited,amount);
    }
};