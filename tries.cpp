#include <string>
#include <iostream>
using namespace std;

struct Node {
    Node *links[26];
    bool endOfWord = false;

    bool containsKey(char ch) {
        if(ch == '.')   return links[26];
        return links[ch - 'a'];
    }

    void put(char ch, Node *node) {
        if(ch == '.')   links[26] = node;
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        if(ch == '.')   return links[26];
        return links[ch - 'a'];
    }

    void setEnd() {
        endOfWord = true;
    }

    bool isEnd() {
        return endOfWord;
    }
};

class Trie {
    Node *root;

public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *node = root;
        for (int i=0; i<word.length(); i++) {
            if(!node->containsKey(word[i]))
                node->put(word[i], new Node());

            node = node->get(word[i]);     //moves to the reference trie node
        }

        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;

        for(int i=0; i<word.length(); i++) {
            if(!node->containsKey(word[i]))
                return false;
            
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node *node = root;

        for(int i=0; i<prefix.length(); i++) {
            if(!node->containsKey(prefix[i]))
                return false;

            node = node->get(prefix[i]);
        }
        return true;
    }
};

/*
//Driver Code

int main() {

    Trie t1;
    
    t1.insert("Nice");
    t1.insert("VeryNice");
    t1.insert("Lul");

    cout << t1.search("Lul");
    cout << t1.startsWith("Very");

    return 0;
}
*/