class Solution {
public:
    typedef pair<int,int>P;
    int DIJ(unordered_map<int,vector<pair<int,int>>>adj,vector<int>dist,int start,int n){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dist[start]=0;
        pq.push({0,start});
        while(!pq.empty()){
            int d=pq.top().first;
            int idx=pq.top().second;
            pq.pop();
            for(auto & it : adj[idx]){
                int nextnode=it.first;
                int wt=it.second;
                if(d+wt< dist[nextnode]){
                    dist[nextnode]=d+wt;
                    pq.push({d+wt,nextnode});
                }
            }
        }
        int mini=INT_MIN;
        for(int i=1;i<=n;i++){
            mini=max(mini,dist[i]);
        }
        if(mini==INT_MAX){
            return -1;
        }
        return mini;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;
        int m=times.size();
        for(int i=0;i<m;i++){
            int u=times[i][0];
            int v=times[i][1];
            int d=times[i][2];
            adj[u].push_back({v,d});
        }
        vector<int>dist(n+1,INT_MAX);
        return DIJ(adj,dist,k,n);
    }
};