class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long fr=accumulate(begin(grid[0]),end(grid[0]),0LL);
        long long sr=0,finalsum=LONG_LONG_MAX;

        for(int i=0;i<grid[0].size();i++){
            fr=fr-grid[0][i];
            long long maxi=max(sr,fr);
            finalsum=min(finalsum,maxi);
            sr=sr+grid[1][i];
        }
        return finalsum;
    }
};