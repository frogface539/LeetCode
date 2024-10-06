class TrieNode{
    public:
    bool isTerminal = false;
    unordered_map<char , TrieNode*>children;
    char value;

    TrieNode(char data){
        this -> value = data;
        this -> isTerminal = false;
    }

    void insertion(TrieNode* root , string word){
        if(word.length() == 0){
            root -> isTerminal = true;
            return;
        }

        char ch = word[0];
        TrieNode* child;
        if(root -> children.count(ch) == 1){
            child = root -> children[ch];
        }

        else{
            child = new TrieNode(ch);
            root -> children[ch] = child;
        }
        insertion(child , word.substr(1));
    }

    bool searching(TrieNode* root , string word){
        if(word.length() == 0){
            return root -> isTerminal;
        }

        char ch = word[0];
        TrieNode* child;

        if(root -> children.find(ch) != root -> children.end()){
            child = root -> children[ch];
        }

        else{
            return false;
        }
        return searching(child , word.substr(1));
    }

    
    bool searchingPrefix(TrieNode* root , string word){
        if(word.length() == 0){
            return true;
        }

        char ch = word[0];
        TrieNode* child;

        if(root -> children.find(ch) != root -> children.end()){
            child = root ->children[ch];
        }

        else{
            return false;
        }
        return searchingPrefix(child , word.substr(1));
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode('-');
    }
    
    void insert(string word) {
        root -> insertion(root , word);
    }
    
    bool search(string word) {
        return root -> searching(root , word);
    }
    
    bool startsWith(string prefix) {
        return root -> searchingPrefix(root , prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */