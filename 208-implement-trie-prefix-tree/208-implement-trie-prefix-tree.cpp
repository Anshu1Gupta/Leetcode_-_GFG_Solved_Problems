struct Node{
        Node* links[26];
        bool end=false;
        
        bool containsKey(char ch){
            return links[ch-'a']!=NULL;
        }
        
        void addKey(char ch,Node* node){
            links[ch-'a']=node;
        }
        
        Node* getKey(char ch){
            return links[ch-'a'];
        }
        
        void makeEnd(){
            end=true;
        }
        bool isEnd(){
            return end;
        }
        
    };
class Trie {
    public:
     Node*root;

    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        
        Node*node=root;
        
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->addKey(word[i],new Node());
                
            }
            node=node->getKey(word[i]);
        }
        
        node->makeEnd();
        
    }
    
    bool search(string word) {
        Node*node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i]))return false;
            else{
                 node=node->getKey(word[i]);
            }
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node*node=root;
        for(int i=0;i<prefix.size();i++){
            if(!node->containsKey(prefix[i]))return false;
            else{
                 node=node->getKey(prefix[i]);
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */