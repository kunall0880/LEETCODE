class Solution {
public:
    // void solve(string & tiles,unordered_set<string> & st,vector<bool> & used,string & curr,int n){
    //     st.insert(curr);
    //     for(int i=0;i<n;i++){
    //         if(used[i]){
    //             continue;
    //         }
    //         used[i]=true;
    //         curr.push_back(tiles[i]);
    //         solve(tiles,st,used,curr,n);
    //         used[i]=false;
    //         curr.pop_back();
    //     }
    // }
    //     int n=tiles.length();
    //     vector<bool>used(n,false);
    //     unordered_set<string>st;
    //     string curr="";
    //     solve(tiles,st,used,curr,n);
    //     return (st.size()-1);
    void solve(vector<int>&nums,int & count){
        count++;
        for(int i=0;i<26;i++){
            if(nums[i]==0){
                continue;
            }
            nums[i]--;
            solve(nums,count);
            nums[i]++;
        }
    }
    int numTilePossibilities(string tiles) {
        vector<int>nums(26,0);
        for(auto & ch : tiles){
            nums[ch-'A']++;
        }
        int count=0;
        solve(nums,count);
        return count-1;
    }
};