class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int>col;
        unordered_map<int,int>idx;
        int n=queries.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            int index=queries[i][0];
            int color=queries[i][1];

            if(idx.count(index)){
                int c=idx[index];
                col[c]--;
                if(col[c]==0){
                    col.erase(c);
                }
            }
            idx[index]=color;
            col[color]++;
            ans.push_back(col.size());
        }
        return ans;
    }
};