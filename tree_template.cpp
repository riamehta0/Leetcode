#include <iostream>
#include <queue>
#include <stack>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void preorder_iterative(node *root)
{
    vector<int> nodes;
    stack<node *> todo;
    while (root || !todo.empty())
    {
        if (root)
        {
            cout << root->data << " ";
            if (root->right)
            {
                todo.push(root->right);
            }
            root = root->left;
        }
        else //if left is null we go to right
        {
            root = todo.top();
            todo.pop();
        }
    }
}
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void inorder_iterative(node *root)
{
    stack<node *> todo;
    while (root || !todo.empty())
    {
        while (root)
        {
            todo.push(root);
            root = root->left;
        }
        root = todo.top();
        todo.pop();
        cout << root->data << " ";
        root = root->right;
    }
}
void levelorder_2(node *root)
{
    if (root == NULL)
        return;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 1; i <= n; i++)
        {
            node *node = q.front();
            q.pop();
            cout << node->data << " ";
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }
}
void levelorder(node *root)
{
    if (root == NULL)
        return;
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *node = q.front();
        q.pop();
        if (node != NULL)
        {
            cout << node->data << " ";
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        cout<<endl;
    }
}
int sum_at_k_level(node *root, int k)
{
    int i = 0;
    int sum = 0;
    if (root == NULL)
        return 0;
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *node = q.front();
        q.pop();
        if (node != NULL)
        {
            if (i == k)
                sum += node->data;
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        else if (!q.empty())
        {
            q.push(NULL);
            i++;
        }
    }
    return sum;
}
int count_node(node *root)
{
    if (root == NULL)
        return 0;
    return count_node(root->left) + count_node(root->right) + 1;
}
int sum_node(node *root)
{
    if (root == NULL)
        return 0;
    return sum_node(root->left) + sum_node(root->right) + root->data;
}
node *mirror(node *root)
{
    if (root == NULL)
        return root;
    node *t = root->left;
    root->left = root->right;
    root->right = t;
    //just interchanging left with right and vice versa
    if (root->left)
        mirror(root->left);
    if (root->right)
        mirror(root->right);

    return root;
}
int height(node *root)
{
    if (root == NULL)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}
int diameter(node *root)
{
    if (root == NULL)
        return 0;
    int h = height(root->left) + height(root->right) + 1;
    return max(h, max(diameter(root->left), diameter(root->right)));
    // checking diameter of both as it is not necessary for diameter to pass form root
}
void printCurrentLevel(node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1)
    {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}
void sum_replacment(node *root)
{
    if (root == NULL)
        return;
    root->data = sum_node(root->left) + sum_node(root->right) + root->data;
    if (root->left)
        sum_replacment(root->left);
    if (root->right)
        sum_replacment(root->right);
}
bool isbalance(node *root)
{
    if (root == NULL)
        return 1;
    int h = height(root->left) - height(root->right);
    if (h < 0)
        h = -h;
    return h <= 1 && isbalance(root->left) && isbalance(root->right);
}
void left_view(node *root)
{
    if (root == NULL)
        return;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 1; i <= n; i++)
        {
            node *node = q.front();
            q.pop();
            if (i == 1)
                cout << node->data << " ";
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
        }
    }
}
void right_view(node *root)
{
    if (root == NULL)
        return;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 1; i <= n; i++)
        {
            node *node = q.front();
            q.pop();
            if (i == n)
                cout << node->data << " ";
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
        }
    }
}
int count_node_2(node *root)
{
    if (root == NULL)
        return 0;
    int l = 0, r = 0;
    l = count_node_2(root->left);
    r = count_node_2(root->right);
    if (root->left && root->right)
        return l + r + 1;
    else
        return l + r;
}
void add_node_bst(node *root, int val)
{
    node *last = new node(val);
    while (root != NULL)
    {
        if (root->data > val && root->left == NULL)
        {
            root->left = last;
            break;
        }
        if (root->data < val && root->right == NULL)
        {
            root->right = last;
            break;
        }
        if (root->data > val)
            root = root->left;
        else
            root = root->right;
    }
}
//for valid bst
bool isValidBST(node *root)
{
    stack<node *> st;
    bool check = false;
    int prev;
    while (root || !st.empty())
    {
        while (root)
        {
            st.push(root);
            root = root->left;
        }
        root = st.top();
        st.pop();
        if (check && root->data < prev)
            return false;
        prev = root->data;
        root = root->right;
        check = true;
    }
    return true;
} 
int isBSTUtil(node* node, int min, int max) 
{ 
    /* an empty tree is BST */
    if (node==NULL) 
        return 1; 
            
    /* false if this node violates
    the min/max constraint */
    if (node->data < min || node->data > max) 
        return 0; 
    
    /* otherwise check the subtrees recursively, 
    tightening the min or max constraint */
    return
        isBSTUtil(node->left, min, node->data-1) && // Allow only distinct values 
        isBSTUtil(node->right, node->data+1, max); // Allow only distinct values 
}
int isBST(node* node) 
{ 
    return(isBSTUtil(node, INT8_MIN, INT8_MAX)); 
}
//end
bool isCompleteTree(node *root)
{
    vector<node *> arr;
    arr.push_back(root);
    int i = 0;
    while (i < arr.size() && arr[i])
    {
        arr.push_back(arr[i]->left);
        arr.push_back(arr[i]->right);
        i++;
    }
    while (i < arr.size() && !arr[i])
        i++;
    return i == arr.size();
}
bool isSumPath(node *root, int sum)
{
    if (root == NULL)
        return false;
    if (root->left == root->right) //shortcut to check both root->left==NULL&&root->right==NULL
        return sum == root->data;
    return isSumPath(root->left, sum - root->data) || isSumPath(root->right, sum - root->data);
    // let sum=4 and tree is 1,2 3,4 5 6 7
    // then we will first go with [root->left(2),4-1]                    [root->right(3),4-1]
    //                   //               \\                                //                \\ 
    //            [root->left(4),3-2]      [root->right(5),3-2]    [root->left(6),3-3]    [root->right(7),3-3]
}
int numberOfUniqueBST(int n)
{
    //This is calalans number  Cn+1 = Sum(Ci*Cn-i) for all 0 <= i <= n
   /*
    * Taking 1~n as root respectively:
    *      1 as root: # of trees = F(0) * F(n-1)  // F(0) == 1
    *      2 as root: # of trees = F(1) * F(n-2) 
    *      3 as root: # of trees = F(2) * F(n-3)
    *      ...
    *      n-1 as root: # of trees = F(n-2) * F(1)
    *      n as root:   # of trees = F(n-1) * F(0)
    *
    * So, the formulation is:
    *      F(n) = F(0) * F(n-1) + F(1) * F(n-2) + F(2) * F(n-3) + ... + F(n-2) * F(1) + F(n-1) * F(0)
    */
    int arr[n + 1];
    arr[0] = 1;
    arr[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        arr[i] = 0;
        for (int j = 0; j < i; j++)
        {
            arr[i] += arr[j] * arr[i - j - 1];
        }
    }
    return arr[n];
}
node *build()
{
    int d;
    cout << "enter the data: ";
    cin >> d;
    if (d == -1)
        return NULL;
    node* temp = new node(d);
    temp->left = build();
    temp->right = build();
    return temp;
}
int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->left->left->left = new node(8);
    root->left->left->right = new node(9);
    inorder_iterative(root);
    cout << endl;
    preorder_iterative(root);
    cout << endl;
    cout << isCompleteTree(root) << endl;
    cout << count_node_2(root) << endl;
}
