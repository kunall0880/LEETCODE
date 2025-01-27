class Solution {
public:
    int DFS(unordered_map<int,vector<int>>&mp,int u, int v,vector<bool>&visit){
        visit[u]=true;
        if(u==v){
            return true;
        }
        bool ans=false;
        for(auto it : mp[u]){
            if(!visit[it]){
                ans = ans || DFS(mp,it,v,visit);
            }
        }
        return ans;
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& nums) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<pre.size();i++){
            int f=pre[i][0];
            int s=pre[i][1];
            mp[f].push_back(s);
        }
        int l=nums.size();
        vector<bool>ans(l,false);
        for(int i=0;i<l;i++){
            int u=nums[i][0];
            int v=nums[i][1];
            vector<bool>visit(n,false);
            ans[i]=DFS(mp,u,v,visit);
        }
        return ans;
    }
};