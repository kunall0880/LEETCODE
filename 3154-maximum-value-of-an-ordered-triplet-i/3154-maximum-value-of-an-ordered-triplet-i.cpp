class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        long long maxdif=0,maxi=0;
        long long res=0;
        for(int i=0;i<n;i++){
            res=max(res,maxdif*(long long)nums[i]);
            maxdif=max(maxdif,maxi-(long long)nums[i]);
            maxi=max(maxi,(long long)nums[i]);
        }
        return res;
    }
};