class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        int count=0,mini=INT_MAX;
        long long sum=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]<0){
                    count++;
                }
                mini=min(mini,abs(matrix[i][j]));
                sum+=abs(matrix[i][j]);
            }
        }   
        if(count%2==1){
            sum=sum-2*mini;
        }
        return sum;
    }
};