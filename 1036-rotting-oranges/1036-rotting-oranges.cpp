class Solution {
public:
    typedef pair<int,int>P;
    vector<vector<int>>dir={{0,1},{0,-1},{-1,0},{1,0}};
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int minmin=0,count=0;
        queue<P>que;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    que.push({i,j});
                }
                if(grid[i][j]==1){
                    count++;
                }
            }
        }
        if(count==0){
            return 0;
        }
        while(!que.empty()){
            int N=que.size();
            while(N--){
                P curr= que.front();
                que.pop();
                int i=curr.first;
                int j=curr.second;

                for(auto it : dir){
                    int i_=i+it[0];
                    int j_=j+it[1];
                    if(i_>=0 && i_<m && j_>=0 && j_<n && grid[i_][j_]==1){
                        grid[i_][j_]=2;
                        count--;
                        que.push({i_,j_});
                    }
                }
            }
            minmin++;
        }
        if(count==0){
            return minmin-1;
        }
        return -1;
    }
};