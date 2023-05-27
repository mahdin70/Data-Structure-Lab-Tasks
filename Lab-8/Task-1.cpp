#include<iostream>
using namespace std;

class TrieNode{
    public:
      char data;
      TrieNode* children[26];
      bool isTerminal;

      TrieNode(char ch){
        data = ch;
        for(int i = 0 ; i < 26 ; i++){
            children[i] = NULL;
        }
        isTerminal = false;
      }
};

class WordDictionary{
    public:
    TrieNode* root;

    WordDictionary(){
        root = new TrieNode('\0');
        cout<<"Object Created"<<endl;
    }

    void addWordHelper(TrieNode* root, string word){
        
        if(word.length()==0){
            root->isTerminal = true;
            return;
        }
       
        int index = word[0]-'a';
        TrieNode* child; 
      
        if(root->children[index]!=NULL){
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        addWordHelper(child,word.substr(1));
    }

    void addWord(string word){
        addWordHelper(root, word);
        cout<<"Word Added"<<endl;
    }


    bool searchHelper(TrieNode* root, string word){
        if(word.length()==0){
            return root->isTerminal;
        }
        int index = word[0] - 'a';
        TrieNode* child;

        if(root->children[index]!=NULL){
            child = root->children[index];
        }
        else{
            return false;
        }
        return searchHelper(child,word.substr(1));
    }

    void search(string word){
        bool flag = searchHelper(root, word);
        if(flag == true){
            cout<<"Word Found"<<endl;
        }
        else{
            cout<<"Word Not Found"<<endl;
        }
    }
};

int main(){
    
    WordDictionary *wd = new WordDictionary();
    
    wd->addWord("bad");
    wd->addWord("dad");
    wd->addWord("mad");
    wd->search("pad");
    wd->search("bad");

    return 0;
}

   



















    