class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>ans;
        if(n==1){
            return 0;
        }
        int len=edges.size();
        for(int i=0;i<n;i++){
            ans[i];
        }
        for(int i=0;i<len;i++){
            ans[edges[i][1]].push_back(edges[i][0]);
        }
        int count=0,answ=-1;
        for(auto it : ans){
            if(it.second.size()==0){
                count++;
                answ=it.first;
            }
        }
        if(count==1){
            return answ;
        }
        return -1;
    }
};