#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Hash{
    public:
    int M,Delta;
    vector<int> v;
    vector<int> done;
    Hash(int M_,int Delta_){
        M=M_;
        Delta=Delta_;
        done=vector<int>(M);
        v=vector<int>(M,-1);
    }
    void Insert(int k){
        int now=k%M;
        int step=0;
        while(done[now]){
            if(step>M){
                cout<<"CAN'T INSERT"<<endl;return;
            }
            step++;
            now+=Delta;
        }
        done[now]=1;
        v[now]=k;
        cout<<"step : "<<step<<endl;
    }
    void print(){
        cout<<"v : ";
        for(auto i:v)cout<<i<<" ";cout<<endl;
    }
    bool search(int k){
        int now=k%M;
        int step=0;
        while(v[now]!=k){
            if(step>M){
                cout<<"CAN'T FOUND"<<endl;return false;
            }
            if(done[now]==false){
                cout<<"CAN'T FOUND"<<endl;return false;
            }
            step++;
            now+=Delta;
        }
        cout<<"FOUNDED"<<endl;
        cout<<"step : "<<step<<endl;
        return true;
    }
};

int main()
{
    Hash h(9,2);
    h.Insert(15);
    h.print();
    h.Insert(13);
    h.print();
    h.Insert(14);
    h.print();
    h.Insert(1);
    h.print();
    h.Insert(7);
    h.print();
    h.Insert(0);
    h.print();
    h.Insert(9);
    h.print();
    h.Insert(2);
    h.print();
    h.Insert(3);
    h.print();

    cout<<h.search(1)<<endl;//ある
    cout<<h.search(1000)<<endl; //ない
}