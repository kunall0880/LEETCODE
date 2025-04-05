class Solution {
public:
    void gensub(vector<vector<int>>&ans,vector<int>&nums,int idx,vector<int>curr){
        if(idx==nums.size()){
            ans.push_back(curr);
            return ;
        }
        curr.push_back(nums[idx]);
        gensub(ans,nums,idx+1,curr);
        curr.pop_back();
        gensub(ans,nums,idx+1,curr);
    }
    int subsetXORSum(vector<int>& nums) {
        int ans=0,n=nums.size();
        vector<vector<int>>all;
        vector<int>sub;
        gensub(all,nums,0,sub);
        int sol=0;
        for(auto it : all){
            int x=0;
            for(auto ele : it){
                x=x^ele;
            }
            sol+=x;
        }
        return sol;
    }
};