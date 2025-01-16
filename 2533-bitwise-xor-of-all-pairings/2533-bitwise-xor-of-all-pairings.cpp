class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans=0;
        int m=nums1.size();
        int n=nums2.size();
        unordered_map<int,long long>mp;
        for(int i=0;i<m;i++){
            mp[nums1[i]]+=n;
        }
        for(int i=0;i<n;i++){
            mp[nums2[i]]+=m;
        }
        for(auto it : mp){
            if(it.second%2==0){
                continue;
            }
            ans=ans^it.first;
        }
        return ans;
    }
};