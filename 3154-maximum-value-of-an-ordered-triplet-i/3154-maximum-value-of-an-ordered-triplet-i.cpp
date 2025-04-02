class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        vector<int>lmax(n,0),rmax(n,0);
        for(int i=1;i<n;i++){
            lmax[i]=max(lmax[i-1],nums[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            rmax[i]=max(rmax[i+1],nums[i+1]);
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            long long a=lmax[i]-nums[i];
            long long b=rmax[i]*a;
            ans=max(ans,b);
        }
        return ans;
    }
};