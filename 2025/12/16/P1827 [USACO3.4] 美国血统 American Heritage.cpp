#include <iostream>

using namespace std;

string inorderStr, preorderStr;

int findInorderIndex(char root, int inL, int inR)
{
    for (int i = inL; i <= inR; i++)
    {
        if (inorderStr[i] == root)
            return i;
    }
    return -1;
}

string buildPost(int inL, int inR, int preL, int preR)
{
    if (inL > inR || preL > preR)
        return "";

    char root = preorderStr[preL];
    int rootIndex = findInorderIndex(root, inL, inR);
    int leftTreeSize = rootIndex - inL;

    string leftPost = buildPost(inL, rootIndex - 1, preL + 1, preL + leftTreeSize);
    string rightPost = buildPost(rootIndex + 1, inR, preL + leftTreeSize + 1, preR);

    return leftPost + rightPost + root;
}

int main()
{
    cin >> inorderStr >> preorderStr;
    int n = inorderStr.length();
    string postorderStr = buildPost(0, n - 1, 0, n - 1);
    cout << postorderStr << endl;
    return 0;
}