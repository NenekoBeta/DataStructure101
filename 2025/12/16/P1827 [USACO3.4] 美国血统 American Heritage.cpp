// #include <iostream>

// using namespace std;

// string inorderStr, preorderStr;

// int findInorderIndex(char root, int inL, int inR)
// {
//     for (int i = inL; i <= inR; i++)
//     {
//         if (inorderStr[i] == root)
//             return i;
//     }
//     return -1;
// }

// string buildPost(int inL, int inR, int preL, int preR)
// {
//     if (inL > inR || preL > preR)
//         return "";

//     char root = preorderStr[preL];
//     int rootIndex = findInorderIndex(root, inL, inR);
//     int leftTreeSize = rootIndex - inL;

//     string leftPost = buildPost(inL, rootIndex - 1, preL + 1, preL + leftTreeSize);
//     string rightPost = buildPost(rootIndex + 1, inR, preL + leftTreeSize + 1, preR);

//     return leftPost + rightPost + root;
// }

// int main()
// {
//     cin >> inorderStr >> preorderStr;
//     int n = inorderStr.length();
//     string postorderStr = buildPost(0, n - 1, 0, n - 1);
//     cout << postorderStr << endl;
//     return 0;
// }

#include <iostream>

using namespace std;

string inOrder, preOrder;
void postOrder(int preL, int preR, int inL, int inR)
{
    if (preL > preR || inL > inR) return;
    
    char root = preOrder[preL];  // Root is first in pre-order
    int i = inL; // Find root in in-order
    while (i <= inR && inOrder[i] != root) i++;  // Find root in in-order
    
    postOrder(preL + 1, preL + (i - inL), inL, i - 1);      // Left subtree
    postOrder(preL + (i - inL) + 1, preR, i + 1, inR);      // Right subtree
    cout << root;  // Output root last (post-order)
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> inOrder >> preOrder;
    postOrder(0, preOrder.length() - 1, 0, inOrder.length() - 1);
    return 0;
}