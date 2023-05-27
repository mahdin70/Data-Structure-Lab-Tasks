#include<bits/stdc++.h>
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
};

int main(){
    int n;
    cin>>n;
    vector<string>v1;

    for(int i = 0 ; i < n ; i++){
        string str;
        cin>>str;
        v1.push_back(str);
    }
    
    WordDictionary *wd = new WordDictionary();
    for(auto a : v1){
        string s1 = v1.back();
        wd->addWord(s1);
        v1.pop_back();
    }
}