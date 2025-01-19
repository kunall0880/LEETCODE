class Solution {
public:
    typedef pair<int,pair<int,int>> PP;
    vector<vector<int>>dir={{0,-1},{0,1},{1,0},{-1,0}};

    int trapRainWater(vector<vector<int>>& height) {

        int m=height.size(),n=height[0].size();
        priority_queue<PP,vector<PP>,greater<>>pq;
        vector<vector<bool>>visit(m,vector<bool>(n,false));

        for(int i=0;i<m;i++){
            for(int c : {0,n-1}){
                pq.push({height[i][c],{i,c}});
                visit[i][c]=true;
            }
        }
        for(int i=0;i<n;i++){
            for(int r : {0,m-1}){
                pq.push({height[r][i],{r,i}});
                visit[r][i]=true;
            }
        }
        int water=0;
        while(!pq.empty()){
            PP pp = pq.top();
            pq.pop();

            int heightcurr = pp.first;
            int i=pp.second.first;
            int j=pp.second.second;
            for(auto it: dir){
                int i_ = i+it[0];
                int j_ = j+it[1];
                if(i_>=0 && i_ <m && j_>=0 && j_<n && !visit[i_][j_]){
                    water+=max(0,heightcurr-height[i_][j_]);
                    pq.push({max(heightcurr,height[i_][j_]),{i_,j_}});
                    visit[i_][j_]=true;
                }
            }
        }
        return water;
    }
};