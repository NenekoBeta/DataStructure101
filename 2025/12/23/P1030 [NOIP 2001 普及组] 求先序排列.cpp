#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string buildPreorder(const string &in, const string &post)
{
    if (in.empty()) return "";
    char root = post.back();
    size_t k = in.find(root);
    string inL = in.substr(0, k);
    string inR = in.substr(k + 1);
    string postL = post.substr(0, k);
    string postR = post.substr(k, post.size() - k - 1);
    return string(1, root) + buildPreorder(inL, postL) + buildPreorder(inR, postR);
}

int main() {
    string inOrder, postOrder;
    cin >> inOrder >> postOrder;
    cout << buildPreorder(inOrder, postOrder);
    return 0;
}