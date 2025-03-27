class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int>map1,map2;
        for(auto it : nums){
            map2[it]++;
        }
        int n=nums.size();
        for(int i=0;i<n;i++){
            map1[nums[i]]++;
            map2[nums[i]]--;
            int n1=i+1;
            int n2=n-i-1;
            if(2*map1[nums[i]]>n1&&2*map2[nums[i]]>n2){
                return i;
            }
        }
        return -1;
    }
};