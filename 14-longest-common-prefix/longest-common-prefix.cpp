class TrieNode{
    public:
    bool isTerminal = false;
    unordered_map<char , TrieNode*>children;
    char value;

    TrieNode(char data){
        this -> value = data;
        this -> isTerminal = false;
    }
};

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

void lcdHelper(TrieNode* root , string &ans){
    if(root -> isTerminal){
        return;
    }
    TrieNode* child ;
    if(root->children.size() == 1){
        for(auto i:root->children){
            char ch = i.first;
            ans.push_back(ch);
            child = i.second;
        }
    }
    else{
        return;
    }

    lcdHelper(child , ans);
}

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        TrieNode* root = new TrieNode('-');
        for(auto i:strs){
            insertion(root , i);
        }

        string ans = "";
        lcdHelper(root , ans);

        return ans;
    }
};