class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long count=0;
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int d=nums[i]-i;
            int good=mp[d];
            int total=i;
            count+=(total-good);
            mp[d]++;
        }
        return count;
    }
};