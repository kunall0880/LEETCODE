class Solution {
public:
    vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    int islandPerimeter(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    for(auto it : dir){
                        int i_=i+it[0];
                        int j_=j+it[1];
                        if(i_>=0&&i_<m&&j_>=0&&j_<n&&grid[i_][j_]==1){
                            continue;
                        }else {
                            count++;
                        }
                    }
                }
            }
        }
        return count;
    }
};