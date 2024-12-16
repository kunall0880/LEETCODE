class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int n=nums.size();
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        while(k--){
            auto ans=pq.top();
            pq.pop();
            pq.push({ans.first*multiplier,ans.second});
        }
        vector<int>res(nums.size());
        while(!pq.empty()){
            auto node =pq.top();
            pq.pop();
            res[node.second]=node.first;
        }
        return res;
    }
};