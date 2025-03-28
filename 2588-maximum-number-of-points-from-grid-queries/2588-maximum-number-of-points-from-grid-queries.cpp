class Solution {
public:
    vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        vector<pair<int,int>>nums;
        for(int i=0;i<queries.size();i++){
            nums.push_back({queries[i],i});
        }
        int m=grid.size();
        int n=grid[0].size();
        sort(nums.begin(),nums.end());
        priority_queue<vector<int>,vector<vector<int>>,greater<>>pq;
        vector<vector<bool>>visit(m,vector<bool>(n,false));
        pq.push({grid[0][0],0,0});
        visit[0][0]=true;
        int count=0;
        vector<int>res(queries.size(),0);
        for(int k=0;k<queries.size();k++){
            int val=nums[k].first;
            int idx=nums[k].second;
            while(!pq.empty()&&pq.top()[0]<val){
                int i=pq.top()[1];
                int j=pq.top()[2];
                pq.pop();
                count++;
                for(auto it : dir){
                    int i_=i+it[0];
                    int j_=j+it[1];
                    if(i_>=0&&i_<m&&j_>=0&&j_<n&&!visit[i_][j_]){
                        pq.push({grid[i_][j_],i_,j_});
                        visit[i_][j_]=true;
                    }
                }
            }
            res[idx]=count;
        }
        return res;
    }
};