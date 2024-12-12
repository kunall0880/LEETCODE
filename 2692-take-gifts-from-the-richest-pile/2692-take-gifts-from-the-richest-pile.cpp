class Solution {
public:
    long long pickGifts(vector<int>& nums, int k) {
        long long sum=0;
        priority_queue<int>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        for(int i=0;i<k;i++){
            int num=pq.top();
            pq.pop();
            pq.push(floor(sqrt(num)));
        }
        while(!pq.empty()){
            sum=sum+pq.top();
            pq.pop();
        }
        return sum;
    }
};