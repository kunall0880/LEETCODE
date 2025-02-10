class Solution {
public:
    vector<int> getRow(int n) {
        vector<int>ans,curr(n+4,0),prev(n+4,0);
        if(n==0){
            return {1};
        }else if(n==1){
            return {1,1};
        } 
        prev[0]=1;
        prev[1]=1;     
        n=n+2;     
        for(int i=2;i<=n;i++){
            for(int j=2;j<=i;j++){
                curr[j]=prev[j]+prev[j-1];
                cout<<curr[j]<<" ";
            }
            prev=curr;
            cout<<endl;
        }
        for(int i=0;i<=n;i++){
            if(prev[i]==0){
                continue;
            }
            ans.push_back(prev[i]);
        }
        return ans;
    }
};