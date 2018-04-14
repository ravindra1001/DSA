#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>
using namespace std;

struct Node{
    char ch;
    int freq;
    Node *  left, * right;
};

Node * newNode(char ch, int freq, Node * left, Node * right){
    Node * node = new Node();
    node->ch  = ch;
    node->freq = freq;
    node->left = left;
    node->right = right;
    return node;
}

class Comp{
    public:
    bool operator()(Node * l, Node * r){
        return l->freq > r->freq;
    }
};

void encode(Node * root, string str, map<char,string> &huffmanCode){
    if(root == NULL) return;
    if(root->left==NULL && root->right == NULL){
        huffmanCode[root->ch] = str;
    }
    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}


void decode(Node * root, int &index, string str){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL){
        cout<<root->ch;
        return;
    }
    index++;

    if(str[index] == '0') decode(root->left, index, str);
    else decode(root->right, index, str);
}

void buildHuffmanTree(string str){
    map<char, int> freq;
    
    for(int i=0;i<str.size();i++){
        freq[str[i]] += 1;
    }

    priority_queue<Node *, vector<Node*>, Comp>pq;

    map<char, int> ::iterator it;    
    for(it=freq.begin();it!=freq.end();it++){
        pq.push(newNode(it->first, it->second, NULL, NULL));
    }

    while(pq.size() != 1){
        Node * left = pq.top();pq.pop();
        Node * right = pq.top();pq.pop();

        int sum = left->freq + right->freq;
        pq.push(newNode('\0', sum, left, right));
    }

    Node * root = pq.top();
    map<char, string>huffmanCode;
    encode(root, "", huffmanCode);

    cout<<"huffman codes are"<<endl;
    for(map<char, string>::iterator it2 = huffmanCode.begin(); it2 != huffmanCode.end();it2++){
        cout<<it2->first<<" : "<<it2->second<<endl;
    }

    string encodedStr = "";
    for(int i=0;i<str.size();i++){
        encodedStr += huffmanCode[str[i]];
    }

    cout<<"encoded string is : "<<encodedStr<<endl;

    cout<<"decode string is"<<endl;
    int index = -1;
    while(index < (int)encodedStr.size()-1){
        decode(root, index, encodedStr);
    }
}

int main(){
    string str = "aaabbcd";
    buildHuffmanTree(str);
    return 0;
}