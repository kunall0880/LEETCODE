class Solution {
public:
    void solve(vector<vector<int>>&nums,vector<int>&ans,int n,vector<int>&sol,unordered_map<int,bool>&mp){
        if(ans.size()==n){
            nums.push_back(ans);
            return ;
        }
        for(int i=0;i<n;i++){
            if(mp[sol[i]]==true){
                continue;
            }
            ans.push_back(sol[i]);
             mp[sol[i]]=true;
            solve(nums,ans,n,sol,mp);
            ans.pop_back();
            mp[sol[i]]=false;
        }
    }
    vector<vector<int>> permute(vector<int>& sol) {
        int n=sol.size();
        vector<vector<int>>nums;
        vector<int>ans;
        unordered_map<int,bool>mp;
        solve(nums,ans,n,sol,mp);
        return nums;
    }
};