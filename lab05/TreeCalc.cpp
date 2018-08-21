

// Insert your header information here
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

#include "TreeCalc.h"
#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;

//Constructor
TreeCalc::TreeCalc() {
    s = new stack<TreeNode*>;
}

//Destructor- frees memory
TreeCalc::~TreeCalc() {
    while(!s->empty()){
        s->pop();
    }
    delete s;
}

//Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* ptr) {
    if (ptr->left != NULL){
        cleanTree(ptr->left);
    }
    if (ptr->right != NULL){
        cleanTree(ptr->right);
    }
}

//Gets data from user
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0]=='/' || response[0]=='*'
            || response[0]=='-' || response[0]=='+' ) {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

//Puts value in tree stack
void TreeCalc::insert(const string& val) {
    // insert a value into the tree
    TreeNode *node = new TreeNode(val);
    if (val[0]=='/' || val[0]=='+' || val[0]=='*' || (val[0]=='-' && !isdigit(val[1]))){
        TreeNode *right = s->top();
        s->pop(); 
        TreeNode *left = s->top();
        s->pop();
        node->left = left;
        node->right = right;
        s->push(node);
    }
    else {
        s->push(node);
    }

}

//Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* ptr) const {
    // print the tree in prefix format
    if (ptr == NULL) {
        return;
    }
    cout << ptr->value << " ";
    if (ptr->left) {
        printPrefix(ptr->left);
    }
    if (ptr->right) {
        printPrefix(ptr->right);
    }
}

//Prints data in infix form
void TreeCalc::printInfix(TreeNode* ptr) const {
    // print tree in infix format with appropriate parentheses
    if (ptr == NULL){
        return;
    }
    if (ptr->left){
        cout << "(";
        printInfix(ptr->left);
    }
    cout << " " << ptr->value << " ";
    if (ptr->right) {
        printInfix(ptr->right);
        cout << ")";
    }
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* ptr) const {
    // print the tree in postfix form
    if (ptr == NULL) {
        return;
    }
    if (ptr->left){
        printPostfix(ptr->left);
    }
    if (ptr->right){
        printPostfix(ptr->right);
    }
    cout << ptr->value << " ";
}

// Prints tree in all 3 (pre,in,post) forms

void TreeCalc::printOutput() const {
    if (s->size()!=0 && s->top()!=NULL) {
        cout << "Expression tree in postfix expression: ";
        printPostfix(s->top());
        cout << endl;
        cout << "Expression tree in infix expression: ";
        printInfix(s->top());
        cout << endl;
        cout << "Expression tree in prefix expression: ";
        printPrefix(s->top());
        cout << endl;
    } else
        cout<< "Size is 0." << endl;
}

//Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* ptr) const {
    // Traverse the tree and calculates the result
    string val = ptr->value;
    if (val[0]=='+'){
        return (calculate(ptr->left) + calculate(ptr->right));
    }
    else if (val[0]=='/'){
        return (calculate(ptr->left)/calculate(ptr->right));
    }
    else if (val[0]=='*'){
        return(calculate(ptr->left)*calculate(ptr->right));
    }
    else if (val[0]=='-' && !isdigit(val[1])){
        return (calculate(ptr->left)-calculate(ptr->right));
    }
    else return atoi(val.c_str());
}

//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
    int i = 0;
    // call private calculate method here
    i = calculate(s->top());
    cleanTree(s->top());
    s->pop();
    return i;
}

