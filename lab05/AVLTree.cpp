#include "AVLTree.h"
#include <string>

using namespace std;

// Implement the following
AVLNode::AVLNode() {
  value = "";
  left = NULL;
  right = NULL;
  height = 0;
}
AVLTree::AVLTree() {
  root = NULL;
  count = 0;
}
AVLTree::~AVLTree() {
  delete root->left;
  delete root->right;
  delete root;
}
void AVLTree::insert(const string& x) {
  AVLNode *curr=root;
  int heightCount = 0;
  while(curr!=NULL){
    if(x<curr->value){
      curr = curr->left;
      heightCount++;
    }
    if(x>curr->value){
      curr=curr->right;
      heightCount++;
    }
  }
  curr= new AVLNode();
  curr->value=x;
  curr->height = heightCount;
  count++;
}
string AVLTree::pathTo(const string& x) const {
  string path = "";
  AVLNode *curr = root;
  while(curr->value != x && curr!=NULL){
    if(x<curr->value){
      path+=curr->value;
      curr = curr->left;
    }
    if(x>curr->value){
      path+=curr->value;
      curr = curr->right;
    }
  }
  if (curr!=NULL){
    return path;
  }
  else {
    return x + "does not exist";
  }
}
bool AVLTree::find(const string& x) const {
  AVLNode *curr=root;
  while(curr->value != x && curr!=NULL){
    if(x<curr->value){
      curr = curr->left;
    }
    if(x>curr->value){
      curr = curr->right;
    }
  }
  if (curr!=NULL){
    return true;
  } else{
    return false;
  }
}
int AVLTree::numNodes() const {
  return count;
}
void AVLTree::balance(AVLNode*& n) {
  if(n->left!=NULL){
    if(n->left->left!=NULL){
      rotateRight(n);
    }
    if(n->left->right!=NULL){
      rotateLeft(n->left);
      rotateRight(n);
    }
  }
  if (n->right!=NULL){
    if(n->right->right!=NULL){
      rotateLeft(n);
    }
    if(n->right->left!=NULL){
      rotateRight(n->right);
      rotateLeft(n);
    }
  }
}
AVLNode* AVLTree::rotateLeft(AVLNode*& n) {}
AVLNode* AVLTree::rotateRight(AVLNode*& n) {}

// The following are implemented for you
// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) { root = remove(root, x); }

// private helper for remove to allow recursion over different nodes. returns
// an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
  if (n == NULL) {
    return NULL;
  }
  // first look for x
  if (x == n->value) {
    // found
    // no children
    if (n->left == NULL && n->right == NULL) {
      delete n;
      return NULL;
    }
    // single child
    if (n->left == NULL) {
      return n->right;
    }
    if (n->right == NULL) {
      return n->left;
    }
    // two children -- tree may become unbalanced after deleting n
    string sr = min(n->right);
    n->value = sr;
    n->right = remove(n->right, sr);
  } else if (x < n->value) {
    n->left = remove(n->left, x);
  } else {
    n->right = remove(n->right, x);
  }
  n->height = 1 + max(height(n->left), height(n->right));
  balance(n);
  return n;
}

// max returns the greater of two integers.
int max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
  // go to bottom-left node
  if (node->left == NULL) {
    return node->value;
  }
  return min(node->left);
}

// height returns the value of the height field in a node. If the node is
// null, it returns -1.
int AVLTree::height(AVLNode* node) const {
  if (node == NULL) {
    return -1;
  }
  return node->height;
}