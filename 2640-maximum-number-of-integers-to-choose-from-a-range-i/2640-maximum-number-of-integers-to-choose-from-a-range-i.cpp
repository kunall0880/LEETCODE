class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int count=-1,sum=0;
        set<int>st(banned.begin(),banned.end());
        for(int i=0;i<=n;i++){
            if(st.find(i)!=st.end()){
                continue;
            }
            else if(sum+i<=maxSum){
                sum=sum+i;
                count++;
            }else{
                break;
            }
        }
        return count;
    }
};