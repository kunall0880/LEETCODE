class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        int n=nums.size();
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
        }
        int count=0;
        while(pq.size()>=2&&pq.top()<k){
            long long t1=pq.top();
            pq.pop();
            long long t2=pq.top();
            pq.pop();
            long long fin=t1*2+t2;
            pq.push(fin);
            count++;
        }
        return count;
    }
};