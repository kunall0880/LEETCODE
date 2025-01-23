class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int maxi=-1e8;
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        vector<int>row(m,0);
        vector<int>col(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    if(row[i]>=2||col[j]>=2){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};