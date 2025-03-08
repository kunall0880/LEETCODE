class Solution {
public:
    int minimumRecolors(string nums, int k) {
        int n=nums.size(),mini=INT_MAX,i=0,j=0;
        int cnt=0;
        while(i<n&&j<n){
            if(nums[j]=='W'){
                cnt++;
            }
            if(j-i+1==k){
                mini=min(mini,cnt);
                if(nums[i]=='W'){
                    cnt--;
                }
                i++;
            }
            j++;
        }
        return mini;
    }
};