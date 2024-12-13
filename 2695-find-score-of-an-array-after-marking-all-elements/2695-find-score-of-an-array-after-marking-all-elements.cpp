class Solution {
public:
    long long findScore(vector<int>& nums) {
        vector<int>visit(nums.size(),-1);
        long long score=0;
        int n=nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }
        while(!pq.empty()){
            auto node =pq.top();
            pq.pop();
            int value=node.first,idx=node.second;
            if(visit[idx]==1){
                continue;
            }
            if(idx-1>=0){
                visit[idx-1]=1;
            }
            if(idx+1<n){
                visit[idx+1]=1;
            }
            score+=value;
        }
        return score;
    }
};