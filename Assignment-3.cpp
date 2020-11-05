#include <bits/stdc++.h>
#define pb push_back
#define vi vector<ll>
#define vs vector<string>
#define all(x) x.begin(), x.end()
#define QuickSort(x) sort(all(x));

using namespace std;

struct Node
{
    string data;
    Node *next;
};

stack<string> st1;

void printQueue(queue<string> q1)
{
    while (!q1.empty())
    {
        cout << q1.front() << " ";
        q1.pop();
    }
    cout << "\n";
}

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

void printLinkedList(vs ll)
{
    for (auto it : ll)
    {
        cout << it << " -> ";
    }
    cout << "NULL\n";
}

int main()
{
    long long int n, i;
    cout<<"> Enter required number of inputs: ";
    cin >> n;
    char ch;
    string str, s1;
    getline(cin, s1);
    vs vec, ll;
    queue<string> q1;
    cout<<"> Enter "<<n<<" inputs now: \n";
    for (i = 0; i < n; i++)
    {
        cout<<"> ";
        getline(cin, str);
        cout<<"> Pushed to queue\n\n";
        vec.pb(str);
        q1.push(str);
    }
    cout<<"> Elements of queue are: ";
    printQueue(q1);
    cout << "\n> Do you wish to continue(Y/N)?";
    cin >> ch;

    if (ch == 'Y' || ch == 'y')
    {

        cout << "\n> Dequeing elements from queue.\n\n";
        cout<<"> Pushing elements onto stack now!!\n\n";
        while (!q1.empty())
        {
            st1.push(q1.front());
            q1.pop();
        }
        cout<<"> Elements successfully pushed to stack\n\n";
        cout<<"> Popping from stack and requeing into queue\n\n";
        while (!st1.empty())
        {
            q1.push(st1.top());
            st1.pop();
        }
        cout<<"> Elements successfully popped from stack\n\n";
        cout<<"> Elements of queue after dequeing are: ";
        printQueue(q1);
        cout << "\n> Do you wish to continue(Y/N)?";
        cin >> ch;

        if (ch == 'Y' || ch == 'y')
        {
            cout<<"\n> Elements successfully inserted into linked list from queue.\n";
            ll = insertInLinkedList(q1);
            cout << "\n> Linked list is: ";
            printLinkedList(ll);
            cout << "\n> Do you wish to continue(Y/N)?";
            cin >> ch;

            if (ch == 'Y' || ch == 'y')
            {
                QuickSort(ll);
                cout << "\n> Applying quicksort to linked list........ \n";
                cout << "\n> Linked list is: ";
                printLinkedList(ll);
                cout << "\n> Do you wish to continue(Y/N)?";
                cin >> ch;
                getline(cin, s1);
                if (ch == 'Y' || ch == 'y')
                {
                    cout<<"\n>Enter new string: ";
                    getline(cin, str);
                    ll.pb(str);
                    cout<<"\n> New string inserted into linked list\n";
                    QuickSort(ll);
                    cout << "\n> Applying quicksort to linked list........ \n";
                    cout << "\n> Linked list is: ";
                    printLinkedList(ll);
                    cout << "\n> Do you wish to continue(Y/N)?";
                    cin >> ch;
                    cout << "\n> Thank you for using me!\n";
                    return 0;
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
    else
    {
        cout << "> Program terminated";
        return 0;
    }
}

/*4
Sujay
Jayvardhan
Sandipan
Vedant*/
