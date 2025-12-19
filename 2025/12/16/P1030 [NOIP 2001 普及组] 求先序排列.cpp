// #include <iostream>
// #include <string>

// using namespace std;

// struct Node {
//     char val;      
//     Node* left;
//     Node* right;

//     Node(char v) : val(v), left(nullptr), right(nullptr) {}
// };

// Node* buildTree(const string& in, const string& post) {
//     // 1) ????????? nullptr ??
//     if (in.empty()) return nullptr;

//     // 2) ??????????
//     char rootVal = post.back();
//     Node* root = new Node(rootVal); // new ?????????????????

//     // 3) ????????????????
//     int k = in.find(rootVal);

//     // 4) ??????? inorder
//     string inLeft  = in.substr(0, k);
//     string inRight = in.substr(k + 1);

//     // 5) ?????????????????
//     string postNoRoot = post.substr(0, post.size() - 1);

//     int leftSize = (int)inLeft.size();

//     // 6) ????????????? postorder
//     string postLeft  = postNoRoot.substr(0, leftSize);
//     string postRight = postNoRoot.substr(leftSize);

//     // 7) ???????????????? root ?
//     root->left  = buildTree(inLeft,  postLeft);
//     root->right = buildTree(inRight, postRight);

//     return root;
// }

// void preorder(Node* root) {
//     if (root == nullptr) return;
//     cout << root->val;
//     preorder(root->left);
//     preorder(root->right);
// }

// void freeTree(Node* root) {
//     if (!root) return;
//     freeTree(root->left);
//     freeTree(root->right);
//     delete root;
// }

// int main() {
//     string inorder, postorder;
//     cin >> inorder >> postorder;

//     Node* root = buildTree(inorder, postorder);
//     preorder(root);
//     cout << "\n";

//     freeTree(root);
//     return 0;
// }

#include <iostream>
#include <string>
using namespace std;

string solve(string in, string post) {
    // ???????
    if (in.empty()) return "";
    
    // ??
    char root = post.back();
    
    // ?????????
    int i = in.find(root);
    
    // ?? = ? + ??? + ???
    return string(1, root) + 
           solve(in. substr(0, i), post.substr(0, i)) + 
           solve(in.substr(i + 1), post.substr(i, post.size() - i - 1));
}

int main() {
    string inorder, postorder;
    cin >> inorder >> postorder;
    cout << solve(inorder, postorder) << endl;
    return 0;
}

