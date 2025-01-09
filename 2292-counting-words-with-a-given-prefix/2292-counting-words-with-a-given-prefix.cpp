struct trieNode{
    trieNode * child[26];
    bool eos;
    int count;
};
trieNode * getNode(){
    trieNode * newNode=new trieNode();
    newNode->eos=false;
    newNode->count=0;
    for(int i=0;i<26;i++){
        newNode->child[i]=NULL;
    }
    return newNode;
}
class trie{
    public:
    trieNode * root;
        trie(){
            root=getNode();
        }   
        void insert(string &str){
            trieNode * p=root;
            for(auto it : str){
                int idx=it-'a';
                if(p->child[idx]==NULL){
                    p->child[idx]=getNode();
                }
                p=p->child[idx];
                p->count++;
            }
            p->eos=true;
        }

        int search(string &str){
            trieNode * p=root;
            for(auto it : str){
                int idx=it-'a';
                if(p->child[idx]==NULL){
                    return 0;
                }
                p=p->child[idx];
            }
            return p->count;
        }
};
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        trie Trie;
        for(auto it : words){
            Trie.insert(it);
        }
        return Trie.search(pref);
    }
};