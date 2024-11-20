class Solution {
public:
    bool chk(vector<int>nums,int x,int k){
        int n=nums.size();
        long long tot=0;
        for(int i=0;i<n;i++){
            tot=tot+(nums[i]+x -1)/x;
        }
        if(tot>k){
            return false;
        }
        return true;
    }
    int bin(vector<int>nums,int mini,int maxi,int k){
        int n=nums.size();
        int l=1,h=maxi,res=INT_MAX;
        while(l<=h){
            int mid=(l+h)/2;
            if(chk(nums,mid,k)){
                res=min(res,mid);
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return res;
    }
    int minEatingSpeed(vector<int>& nums, int h) {
        int mini=INT_MAX,maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            mini=min(mini,nums[i]);
            maxi=max(maxi,nums[i]);
        }
        return bin(nums,mini,maxi,h);
    }
};