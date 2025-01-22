class Solution {
public:
    typedef pair<int,int>P;
    vector<vector<int>>dir={{0,1},{0,-1},{-1,0},{1,0}};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size();
        int n=isWater[0].size();

        vector<vector<int>>height(m,vector<int>(n,-1));
        queue<P>qu;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]==1){
                    height[i][j]=0;
                    qu.push({i,j});
                }
            }
        }

        while(!qu.empty()){
            int N=qu.size();
            while(N--){
                P curr=qu.front();
                qu.pop();

                int i=curr.first;
                int j=curr.second;

                for(auto it : dir){
                    int i_=i+it[0];
                    int j_=j+it[1];
                    if(i_>=0 && i_<m && j_>=0 && j_<n && height[i_][j_]==-1){
                        height[i_][j_]=height[i][j]+1;
                        qu.push({i_,j_});
                    }
                }
            }
        }

        return height;
    }
};