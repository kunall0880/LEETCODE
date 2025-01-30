class Solution {
public:
    vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    void DFS(int i,int j,vector<vector<bool>>&visit,vector<vector<char>>adj){
        visit[i][j]=true;
        int m=adj.size(),n=adj[0].size();
        for(auto it : dir){
            int i_=i+it[0];
            int j_=j+it[1];
            if(i_>=0&&i_<m&&j_>=0&&j_<n&&adj[i_][j_]=='X'&&visit[i_][j_]==false){
                DFS(i_,j_,visit,adj);
            }
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int m=board.size(),n=board[0].size();
        int count=0;
        vector<vector<bool>>visit(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visit[i][j]&&board[i][j]=='X'){
                    count++;
                    DFS(i,j,visit,board);
                }
                //cout<<visit[i][j]<<" ";
            }
           // cout<<endl;
        }
        return count;
    }
};