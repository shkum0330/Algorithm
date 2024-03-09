#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Node{
    int idx,x,y;
    Node* left;
    Node* right;
};
vector<Node> node;
vector<int> pre,post;
int edge[10001][10001];

bool compare(const Node& a, const Node& b){
    if(a.y==b.y) return a.x<b.x;
    return a.y>b.y;
}

void preorder(Node* node){
    if(node == NULL) return;
    pre.push_back(node->idx);
    preorder(node->left);
    preorder(node->right);
}

void postorder(Node* node){
    if(node == NULL) return;
    postorder(node->left);
    postorder(node->right);
    post.push_back(node->idx);
}

void make_tree(Node* parent, Node* child){
    if(parent->x<child->x){
        if(parent->right==NULL){
            parent->right=child;
        }else{
            make_tree(parent->right,child);
        }
    }
    if(parent->x>child->x){
        if(parent->left==NULL){
            parent->left=child;
        }else{
            make_tree(parent->left,child);
        }
    }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    for(int i=0;i<nodeinfo.size();i++){
        node.push_back({i+1,nodeinfo[i][0],nodeinfo[i][1],NULL,NULL}); // y,x 순으로
    }
    
    sort(node.begin(),node.end(),compare);

    for(int i=1;i<node.size();i++){
        make_tree(&node[0],&node[i]);
    }
    preorder(&node[0]);
    postorder(&node[0]);
    answer.push_back(pre);
    answer.push_back(post);
    return answer;
}
