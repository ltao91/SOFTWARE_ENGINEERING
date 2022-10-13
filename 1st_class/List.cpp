#include <bits/stdc++.h>

using namespace std;
#define INF ((1ll) << 60)
#define rep(i, n) for (long long i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

template <class T>
class Node
{
public:
    Node<T> *before, *after;
    bool be = false, af = false;
    T key;
    Node()
    {
    }
    Node(T x)
    {
        key = x;
    }
};

template <class T>
class List
{
public:
    Node<T> *root;
    Node<T> *end;
    bool ro = false, en = false;
    List()
    {
    }
    void push(T key)
    {
        Node<T> *node = new Node<T>(key);
        push(node);
    }
    void push(Node<T> *node)
    {
        if (!ro)
        {
            root = node;
            ro = true;
        }
        else
        {
            if (!en)
            {
                root->after = node;
                node->before = root;
                end = node;
                root->af = true;
                en = true;
                end->be = true;
            }
            else
            {
                end->after = node;
                node->before = end;
                end->af = true;
                node->be = true;
                end = node;
            }
        }
    }
    void debug(){
        if(ro==false){
            cout<<"EMPTY"<<endl;
            return;
        }
        map<Node<T>*,ll> NUM; 

        auto now=root;
        int i=0;
        while(true){
            NUM[now]=i;
            i++;
            if(now->af==false)
            break;
            now=now->after;
        }
        now=root;
        while(true){
            cout<<"Node : "<<NUM[now]<<endl;
            cout<<"  Key : "<<now->key<<endl;
            cout<<"  be,af : "<<now->be<<" "<<now->af<<endl;
            cout<<"  before,after : "<<(now->be?NUM[now->before]:-1)<<" "<<(now->af?NUM[now->after]:-1)<<endl;
            if(now->af==false)
            break;
            now=now->after;
        }
    }

    void print()
    {
        if(ro==false){
            cout<<"EMPTY"<<endl;
            return;
        }
        auto now = root;
        while (true)
        {
            cout << now->key << " ";
            if (now->af == false)
                break;
            now = now->after;
        }
        cout << endl;
    }
    bool search(T key)
    {
        auto now = root;
        while (true)
        {
            if (now->key == key)
                return true;
            if (now->af == false)
                break;
            now = now->after;
        }
        return false;
    }
    Node<T> *search_node(T key)
    {
        if(ro==false){
            cout<<"EMPTY"<<endl;
            assert(0);
        }
        auto now = root;
        while (true)
        {
            if (now->key == key)
            {
                return now;
            }
            if (now->af == false)
                break;
            now = now->after;
        }
        // not founded
        assert(0);
        return now;
    }
    void Delete(T k)
    {
        if (!search(k))
            return;
        Delete(search_node(k));
    }
    void Delete(Node<T> *node)
    {
        if (ro == false)
        {
            return;
        }
        if (en == false)
        {
            ro = false;
            return;
        }
        if (node == root)
        {
            node->after->be = false;
            if(node->after==end)en=false;
            root = node->after;
        }
        else if (node == end)
        {
            node->before->af = false;
            if(node->before==root)en=false;
            end = node->before;
        }
        Node<T> *left = node->before, *right = node->after;
        node->after->before = left;
        node->before->after = right;
        delete node;
    }
};

int main()
{
    List<int>* l=new List<int>();
    int MAX=10000;
    for(int i=0;i<MAX;i+=3){
        l->push(i);
    }
    l->print();
    cout<<endl;cout<<endl;
    for(int i=0;i<MAX;i+=2){
        l->Delete(i);
    }
    l->print();
    delete l;
    return 0;
}
