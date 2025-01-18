class Solution {
public:
    vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        priority_queue<vector<int>,vector<vector<int>>,greater<>>pq;
        vector<vector<int>>result(m,vector<int>(n,INT_MAX));
        pq.push({0,0,0});
        result[0][0]=0;
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int currCost=curr[0],i=curr[1],j=curr[2];

            for(int idx=0;idx<=3;idx++){
                int dir_i= i + dir[idx][0];
                int dir_j= j + dir[idx][1];

                if(dir_i>=0 && dir_i<m && dir_j>=0 && dir_j<n){
                    int grid_dir=grid[i][j];
                    int newcost=currCost;
                    if(grid_dir-1 != idx){
                        newcost+=1;
                    }
                    if(newcost < result[dir_i][dir_j]){
                        result[dir_i][dir_j]=newcost;
                        pq.push({newcost,dir_i,dir_j});
                    }
                }
            }
        }
        return result[m-1][n-1];
    }
};