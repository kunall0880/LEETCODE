class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>mp(26,0);
        for(auto it : tasks){
            mp[it-'A']++;
        }
        priority_queue<int>pq;
        for(int i=0;i<26;i++){
            if(mp[i]>0){
                pq.push(mp[i]);
            }
        }
        int ans=0;
        while(!pq.empty()){
            vector<int>temp;
            for(int i=0;i<=n;i++){
                if(!pq.empty()){
                    int curr=pq.top();
                    curr--;
                    temp.push_back(curr);
                    pq.pop();
                }
            }
            for(auto it : temp){
                if(it>0){
                    pq.push(it);
                }
            }
            if(pq.empty()){
                ans+=temp.size();
            }else{
                ans+=(n+1);
            }
        }
        return ans;
    }
};