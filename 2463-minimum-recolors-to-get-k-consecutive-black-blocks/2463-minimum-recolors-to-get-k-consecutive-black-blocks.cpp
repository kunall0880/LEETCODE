class Solution {
public:
    int minimumRecolors(string nums, int k) {
        int n=nums.size(),mini=INT_MAX,w=0;
        for(int i=0;i<n-k+1;i++){
            w=0;
            for(int j=i;j<i+k;j++){
                if(nums[j]=='W'){
                    w++;
                }
            }
            mini=min(mini,w);
        }
        return mini;
    }
};