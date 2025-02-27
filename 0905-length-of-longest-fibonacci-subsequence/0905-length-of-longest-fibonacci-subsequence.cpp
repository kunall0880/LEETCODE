class Solution {
public:
    int solve(int j,int k,vector<int>&nums,unordered_map<int,int>&mp){
        int get=nums[k]-nums[j];
        if(mp.count(get)&&mp[get]<j){
            return solve(mp[get],j,nums,mp)+1;
        }
        return 2;
    }
    int lenLongestFibSubseq(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]=i;
        }
        int maxi=0;
        for(int j=1;j<n;j++){
            for(int k=j+1;k<n;k++){
                int len=solve(j,k,nums,mp);
                if(len>=3){
                    maxi=max(maxi,len);
                }
            }
        }
        return maxi;
    }
};