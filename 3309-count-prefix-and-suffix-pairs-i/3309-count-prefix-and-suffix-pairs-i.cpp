struct trieNode{
    struct trieNode * child[26];
    bool isend;
};
struct trieNode * getnode(){
    struct trieNode * newNode = new trieNode();
    newNode->isend=false;
    for(int i=0;i<26;i++){
        newNode->child[i]=NULL;
    }
    return newNode;
}
class Trie{
    public:
    struct trieNode * root;
    Trie(){
        root=getnode();
    }
    void insert(string word){
        struct trieNode * p = root;
        for(auto it : word){
            int idx=it-'a';
            if(p->child[idx]==NULL){
                p->child[idx]=getnode();
            }
            p=p->child[idx];
        }
        p->isend=true;
    }
    bool search(string str){
        struct trieNode * p=root;
        for(auto it : str){
            int idx=it-'a';
            if(p->child[idx]==NULL){
                return false;
            }
            p=p->child[idx];
        }
        return true;
    }
};
class Solution {
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        long long count=0;
        int n=words.size();
        for(int j=0;j<n;j++){
            Trie t1,t2;
            t1.insert(words[j]);

            string str1=words[j];
            reverse(str1.begin(),str1.end());

            t2.insert(str1);

            for(int i=0;i<j;i++){
                if(words[j].length()<words[i].length()){
                    continue;
                }
                string str2=words[i];
                
                reverse(str2.begin(),str2.end());

                if(t1.search(words[i])==true&&t2.search(str2)==true){
                    count++;
                }
            }
        }
        return count;
    }
};