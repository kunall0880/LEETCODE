class Solution {
public:
    bool solve(int idx,vector<int>&result,vector<bool>&used,int n){
        if(idx >= result.size()){
            return true;
        }
        if(result[idx]!=-1){
            return solve(idx+1,result,used,n);
        }
        for(int i=n;i>=1;i--){
            if(used[i]==true){
                continue;
            }
            result[idx]=i;
            used[i]=true;
            if(i==1){
                if(solve(idx+1,result,used,n)==true){
                    return true;
                }
            }else{
                int j=idx+result[idx];
                if(j<result.size()&&result[j]==-1){
                    result[j]=i;
                    if(solve(idx+1,result,used,n)==true){
                        return true;
                    }
                    result[j]=-1;
                }
            }
            result[idx]=-1;
            used[i]=false;
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int>result(2*n-1,-1);
        vector<bool>used(n+1,false);
        solve(0,result,used,n);
        return result;
    }
};