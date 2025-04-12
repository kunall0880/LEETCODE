class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        unordered_set<string>st;
        vector<long long>fact(11,1);
        for(int i=1;i<11;i++){
            fact[i]=fact[i-1]*i;
        }
        long long res=0;
        int d=(n+1)/2;
        int start = pow(10,d-1);
        int end = pow(10,d)-1;

        for(int i=start;i<=end;i++){
            string left=to_string(i);
            string full="";
            if(n%2==0){
                string right=left;
                reverse(right.begin(),right.end());
                full=left+right;
            }else{
                string right = left.substr(0,d-1);
                reverse(right.begin(),right.end());
                full=left+right;
            }
            long long num = stoll(full);
            if(num%k!=0){
                continue;
            }
            sort(full.begin(),full.end());
            st.insert(full);
        }
        for(auto it : st){
            vector<int>count(10,0);
            for(char ch : it){
                count[ch-'0']++;
            }
            int total = it.length();
            int zero=count[0];
            int nonzero=total-zero;

            long long ans = (nonzero*fact[total-1]);
            
            for(int i=0;i<10;i++){
                ans=ans/fact[count[i]];
            }
            res=res+ans;
        }
        return res;
    }
};