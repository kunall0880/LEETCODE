class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long count=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]=nums[i]-i;
        }
        unordered_map<int,int>mp;
        mp[nums[0]]++;
        for(int i=1;i<n;i++){
            int hmny=mp[nums[i]];
            int j=i;
            count+=(j-hmny);
            mp[nums[i]]++;
        }
        return count;
    }
};