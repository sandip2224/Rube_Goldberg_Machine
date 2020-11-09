#include <bits/stdc++.h>
#define pb push_back
#define vi vector<ll>
#define vs vector<string>
#define all(x) x.begin(), x.end()
#define Sort(x) sort(all(x));

using namespace std;

// Tree declaration
struct Node
{
public:
    string data;
    Node *left;
    Node *right;

    Node(string x)
    {
        data = x;
        left = right = NULL;
    }
};

stack<string> st1;
vector<string> linkedlist;

/*---------------------------------------------*/
Node *buildtree(vector<string> arr, int n)
{

    queue<Node *> q;
    Node *root = new Node(arr[0]);
    q.push(root);
    q.push(NULL);

    int i = 1;
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        if (curr == NULL)
        {
            q.push(NULL);
            continue;
        }

        if (i == n)
            break;
        curr->left = new Node(arr[i]);
        ++i;
        q.push(curr->left);

        if (i == n)
            break;

        curr->right = new Node(arr[i]);
        ++i;

        q.push(curr->right);
    }

    return root;
}

/*---------------------------------------------*/
void print2DUtil(Node *root, int space)
{
    // Base case
    if (root == NULL)
        return;
    space += 10;
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    cout << "\n";
    for (int i = 10; i < space; i++)
        cout << " ";

    cout << root->data << "\n";

    // Process left child
    print2DUtil(root->left, space);
}

/*---------------------------------------------*/
void print2D(Node *root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}

/*--------------------------------------------------*/
void printPreOrder(struct Node *node)
{
    if (node == NULL)
        return;

    /* first print data of node */
    cout << node->data << " ";

    /* then recur on left sutree */
    printPreOrder(node->left);

    /* now recur on right subtree */
    printPreOrder(node->right);
}

/*--------------------------------------------------*/
void printInorder(struct Node *node)
{
    if (node == NULL)
        return;

    /* first recur on left child */
    printInorder(node->left);

    /* then print the data of node */
    linkedlist.pb(node->data);

    cout << node->data << " -> ";

    /* now recur on right child */
    printInorder(node->right);
}

/*--------------------------------------------------*/
void printPostorder(struct Node *node)
{
    if (node == NULL)
        return;

    // first recur on left subtree
    printPostorder(node->left);

    // then recur on right subtree
    printPostorder(node->right);

    // now deal with the node
    cout << node->data << " ";
}

/*--------------------------------------------------*/
void printQueue(queue<string> q1)
{
    while (!q1.empty())
    {
        cout << q1.front() << " ";
        q1.pop();
    }
    cout << "\n";
}

/*--------------------------------------------------*/
vs insertInLinkedList(queue<string> q1)
{
    vs ll;
    while (!q1.empty())
    {
        ll.pb(q1.front());
        q1.pop();
    }
    return ll;
}

/*--------------------------------------------------*/
void printLinkedList(vs ll)
{
    for (auto it : ll)
    {
        cout << it << " -> ";
    }
    cout << "NULL\n";
}

/*--------------------------------------------------*/
int main()
{
    long long int n, i;
    cout << "> Enter required number of inputs: ";
    cin >> n;
    char ch;
    string str, s1;
    getline(cin, s1);
    vs vec, ll;
    queue<string> q1;
    cout << "> Enter " << n << " inputs now: \n";
    for (i = 0; i < n; i++)
    {
        cout << "> ";
        getline(cin, str);
        cout << "> Pushed to queue\n\n";
        vec.pb(str);
        q1.push(str);
    }
    cout << "> Elements of queue are: ";
    printQueue(q1);
    cout << "\n> Do you wish to continue(Y/N)?";
    cin >> ch;

    if (ch == 'Y')
    {

        cout << "\n> Dequeing elements from queue.\n\n";
        cout << "> Pushing elements onto stack now!!\n\n";
        while (!q1.empty())
        {
            st1.push(q1.front());
            q1.pop();
        }
        cout << "> Elements successfully pushed to stack\n\n";
        cout << "> Popping from stack and requeing into queue\n\n";
        while (!st1.empty())
        {
            q1.push(st1.top());
            st1.pop();
        }
        cout << "> Elements successfully popped from stack\n\n";
        cout << "> Elements of queue after dequeing are: ";
        printQueue(q1);
        cout << "\n> Do you wish to continue(Y/N)?";
        cin >> ch;

        if (ch == 'Y')
        {
            cout << "\n> Inserting elements from queue to binary tree in level-order fashion\n";
            Node *root = buildtree(vec, n);
            print2D(root);
            cout << "\n\n> Level order insertion into binary tree successful\n";
            cout << "\n> ELements of binary tree in pre-order fashion: ";
            printPreOrder(root);

            cout << "\n\n> Do you wish to continue(Y/N)?";
            cin >> ch;
            if (ch == 'Y')
            {
                cout << "\nELements of binary tree in post-order fashion: ";
                printPostorder(root);

                cout << "\n\n> Do you wish to continue(Y/N)?";
                cin >> ch;
                if (ch == 'Y')
                {

                    cout << "\n> Inserting elements into linked list in inorder fashion\n";
                    cout << "\n> Insertion successful\n";
                    printInorder(root);
                    cout << "NULL";

                    cout << "\n\n> Do you wish to continue(Y/N)?";
                    cin >> ch;
                    if (ch == 'Y')
                    {
                        cout << "\n> Applying quicksort to linked list........ \n";
                        Sort(linkedlist);
                        cout << "\n> Linked list is: ";
                        printLinkedList(linkedlist);
                        getline(cin, s1);
                        do
                        {
                            cout << "\n>Enter new string: ";
                            getline(cin, str);
                            linkedlist.pb(str);
                            cout << "\n> New string inserted into linked list\n";
                            Sort(linkedlist);
                            cout << "\n> Applying quicksort to linked list........ \n";
                            cout << "\n> Linked list is: ";
                            printLinkedList(linkedlist);
                            cout << "\n> Do you wish to continue(Y/N)?";
                            cin >> ch;
                            getline(cin, str);
                        } while (ch == 'Y');

                        cout<< "\n> Thank you for using me!\n";
                        return 0;
                    }
                    else
                    {
                        cout << "Program terminated!";
                        return 0;
                    }
                }
                else
                {
                    cout << "Program terminated!";
                    return 0;
                }
            }
            else
            {
                cout << "> Program terminated";
                return 0;
            }
        }
        else
        {
            cout << "> Program terminated";
            return 0;
        }
    }
    else
    {
        cout << "> Program terminated";
        return 0;
    }
}
