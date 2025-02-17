class Solution {
public:
    void solve(string & tiles,unordered_set<string> & st,vector<bool> & used,string & curr,int n){
        st.insert(curr);
        for(int i=0;i<n;i++){
            if(used[i]){
                continue;
            }
            used[i]=true;
            curr.push_back(tiles[i]);
            solve(tiles,st,used,curr,n);
            used[i]=false;
            curr.pop_back();
        }
    }
    int numTilePossibilities(string tiles) {
        int n=tiles.length();
        vector<bool>used(n,false);
        unordered_set<string>st;
        string curr="";
        solve(tiles,st,used,curr,n);
        return (st.size()-1);
    }
};