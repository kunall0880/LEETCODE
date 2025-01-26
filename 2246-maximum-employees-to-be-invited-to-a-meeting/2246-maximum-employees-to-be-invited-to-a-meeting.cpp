class Solution {
public:
    int BFS(int start,unordered_map<int,vector<int>>&adj,vector<bool>&visit){
        queue<pair<int,int>>que;
        que.push({start,0});
        int maxdist=0;

        while(!que.empty()){
            auto [currnode,dist]=que.front();
            que.pop();
            for(auto it : adj[currnode]){
                if(!visit[it]){
                    visit[it]=true;
                    que.push({it,dist+1});
                    maxdist=max(maxdist,dist+1);
                }
            }
        }
        return maxdist;
    }
    int maximumInvitations(vector<int>& favorite) {
        int n=favorite.size();
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<n;i++){
            int u=i;
            int v=favorite[i];
            adj[v].push_back(u);
        }
        int longcycle=0;
        int happycount=0;
        
        vector<bool>visit(n,false);
        for(int i=0;i<n;i++){
            if(!visit[i]){
                unordered_map<int,int>mp;
                int currnode=i;
                int nodecount=0;
                while(!visit[currnode]){
                    visit[currnode]=true;
                    mp[currnode]=nodecount;

                    int nextnode=favorite[currnode];
                    nodecount+=1;
                    if(mp.count(nextnode)){
                        int cyclelen=nodecount-mp[nextnode];
                        longcycle=max(longcycle,cyclelen);

                        if(cyclelen==2){
                            vector<bool>visited(n,false);
                            visited[currnode]=true;
                            visited[nextnode]=true;
                            happycount+=2+BFS(currnode,adj,visited)+BFS(nextnode,adj,visited);
                        }
                        break;
                    }
                    currnode=nextnode;
                }
            }
        }
        return max(happycount,longcycle);
    }
};