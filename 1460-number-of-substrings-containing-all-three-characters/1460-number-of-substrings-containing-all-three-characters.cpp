class Solution {
public:
    int numberOfSubstrings(string s) {
        int a = 0, b = 0, c = 0;
        int n = s.length();
        int count = 0;
        int i=0,j=0;
        while (j < n) {
            if (s[j] == 'a') {
                a++;
            } else if (s[j] == 'b') {
                b++;
            } else if (s[j] == 'c') {
                c++;
            }
            while(i<n&&a&&b&&c){
                count+=(n-j);
                if(s[i]=='a'){
                    a--;
                }else if(s[i]=='b'){
                    b--;
                }else{
                    c--;
                }
                i++;
            }
            j++;
        }
        return count;
    }
};

// for(int i=0;i<n;i++){
//      a=0,b=0,c=0;
//      for(int j=i;j<n;j++){
//          if(s[j]=='a'){
//              a++;
//          }else if(s[j]=='b'){
//              b++;
//          }else if(s[j]=='c'){
//              c++;
//          }

//         if(a&&b&&c){
//             //cout<<a<<b<<c<<endl;
//             count++;
//         }
//     }
// }
// return count;