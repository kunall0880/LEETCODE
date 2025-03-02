class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int>mp;
        int n=nums1.size();
        for(int i=0;i<n;i++){
            mp[nums1[i][0]]+=nums1[i][1];
        }
        n=nums2.size();
        for(int i=0;i<n;i++){
            mp[nums2[i][0]]+=nums2[i][1];
        }
        vector<vector<int>>nums;
        for(auto it : mp){
            nums.push_back({it.first,it.second});
        }
        return nums;
    }
};