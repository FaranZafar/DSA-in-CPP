#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int val){
        data=val;
        left=right=NULL;
    }
};
static int idx=-1;
node* buildtree(vector<int> preorder){
    idx++;
    if (preorder[idx]==-1)
    {
        return NULL;
    }
    node* root=new node(preorder[idx]);
    root->left=buildtree(preorder);
    root->right=buildtree(preorder);
    return root;
}
//  preOrder Traversal
void preOder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOder(root->left);
    preOder(root->right);
}
// inOrder traversal 
void inOrder(node* root){
    if (root==NULL)
    {
       return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
    
}
void postOrder(node* root){
    if (root==NULL)
    {
        return;
    }
postOrder(root->left);
postOrder(root->right);
cout<<root->data<<" ";
    
}

// level order
void levelOrder(node* root){
    queue <node*> q;
    q.push(root);
    q.push(NULL);
    while(q.size()>0){
        node* curr=q.front();
        q.pop();
   if (curr==NULL){
   if (!q.empty())
   {
    cout<<endl;
    q.push(NULL);
    continue;
   }else{
       break;
   }
   
   }

        cout<<curr->data<<" ";
        if(curr->left!=NULL){
            q.push(curr->left);
        }
        if (curr->right!=NULL)
        {
        q.push(curr->right);
        }
        
    }
    cout<<endl;
}


int main(){
   vector<int> preoder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
   node* root=buildtree(preoder);
   preOder(root);
   cout<<endl;
   inOrder(root);
   cout<<endl;
   postOrder(root);
   cout<<endl;
   levelOrder(root);

//    cout<<root->data<<endl;
//    cout<<root->left->data<<endl;
//    cout<<root->right->data<<endl;
   return 0;
}