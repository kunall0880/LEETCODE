class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int curr=0,prev=0,time=0,n=colors.size();
        for(int i=0;i<n;i++){
            if(i>0 && colors[i-1]!=colors[i]){
                prev=0;
            }
            curr=neededTime[i];
            time+=min(curr,prev);
            prev=max(curr,prev);
        }
        return time;
    }
};