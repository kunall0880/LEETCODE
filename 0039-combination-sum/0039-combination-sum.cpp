class Solution {
public:
    void solve(vector<int>& nums, int target,int idx,vector<int>curr,vector<vector<int>>&st){
        if(idx==nums.size()){
            if(target==0){
                st.push_back(curr);
            }
            return;
        }
        if(nums[idx]<=target){
            curr.push_back(nums[idx]);
            solve(nums,target-nums[idx],idx,curr,st);
            curr.pop_back();
        }
        solve(nums,target,idx+1,curr,st);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>curr;
        solve(nums,target,0,curr,ans);
        return ans;
    }
};