#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct trie{
    bool end;
    trie *node[26];
    trie(){
        end = false;
        for (int i = 0; i < 26; i++) node[i] = NULL;
    }

    ~trie(){
        for(int i = 0 ; i < 26 ; i++) 
            if(node[i]) delete node[i];
    }

    void insert(string &word, int index){
        
        if(index >= word.size())
            end = true;
        else{        
            int idx = word[index] - 'a';
            if(node[idx] == NULL) 
                node[idx] = new trie();
            node[idx]->insert(word, index+1);
        }
        
    }
    bool find(string &word, int index){

        if(index >= word.size()){
            if(end == true) return true;
            else return false;
        }
        else{
            int idx = word[index] - 'a';
            if(node[idx] == NULL) 
                return false;
            else return node[idx]->find(word, index+1);
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N,M;
    int answer = 0;
    string inputStr;
    trie root;

    cin >> N >> M;
    
    for(int i = 0 ; i < N ; i++){
        cin >> inputStr;
        root.insert(inputStr,0);
    }
    
    for(int i = 0 ; i < M ; i++){
        cin >> inputStr;
        if(root.find(inputStr,0)) answer++;
    }
    cout << answer;
}