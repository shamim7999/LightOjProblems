#include<bits/stdc++.h>
using namespace std;
#define dd double
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define ll long long
#define ull unsigned long long
#define ld long double
#define mx 100005
#define mod 1000000007
#define fr first
#define cti(a) (a-48)
#define itc(a) char(a+48)
#define se second
#define End cout<<"\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define memo(Array,val) memset(Array, val, sizeof Array)
#define PI acos(-1)
bool check(ll n, ll pos){ return (n&(1<<pos)); }
bool Set(ll n, ll pos) {  return (n | (1<<pos)); }
ld LOG(ld b, ld e){ return log(b)/log(e); }

int tc=1, tot=0, sz=0, hold;
bool success=1, del;

struct node
{
    node *next;
    int roll;
};

node *root = NULL;


void appendLast(int r)
{
    if(tot == sz){
        printf("The queue is full\n");
        success=0;
        return;
    }
    node *curr = root;
    if(curr == NULL){
        root = new node();
        root->roll = r;
        root->next = NULL;
        tot++;
    }
    else{
        while(curr->next!=NULL){
            curr = curr->next;
        }
        node *newNode = new node();
        newNode->roll = r;
        newNode->next = NULL;
        curr->next = newNode;
        tot++;
    }

}

void appendAhead(int r)
{
    if(tot == sz){
        printf("The queue is full\n");
        success=0;
        return;
    }
    node *curr = root, *prev = NULL;
    if(root == NULL){
        appendLast(r);
        return;
    }

    node *newNode = new node();
    newNode->roll = r;
    newNode->next = curr;
    root = newNode;
    tot++;
}

void appendAt(int r, int pos)
{
    if((pos-1>tot) || (pos-1)<0){
        cout << "Invalid Position.\n";
        return;
    }
    if(root == NULL){
        appendLast(r);
        return;
    }
    node *curr = root, *prev = NULL;
    if(pos == 1){
        node *newNode = new node();
        newNode->roll = r;
        newNode->next = curr;
        root = newNode;
        tot++;
    }
    else{
        --pos;
        while(pos--){
            prev = curr;
            curr = curr->next;
        }
        node *newNode = new node();
        newNode->roll = r;
        newNode->next = curr;
        prev->next = newNode;
        tot++;
    }

}
void deleteAt(int pos)
{
    if(root == NULL){
        cout << "No Elements.\n";
        return;
    }
    if((pos-1>tot) || (pos-1)<0){
        cout << "Invalid Position.\n";
        return;
    }
    node *curr = root, *prev = NULL;
    if(pos == 1){
        tot--;
        root = root->next;
        delete(curr);
        return;
    }

    --pos;
    while(pos--){
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    delete(curr);
    tot--;

}

void deleteAhead()
{
    if(del){
        if(root == NULL){
            del=0;
            return;
        }
    }

    if(root == NULL){
        printf("The queue is empty\n");
        success=0;
        return;
    }
    node *curr = root;
    root = root->next;
    hold = curr->roll;
    delete(curr);
    tot--;

}

void delAll()
{
    del=1;
    for(int i=0; i<sz; i++){
        if(!del) return;
        deleteAhead();
    }
}

void deleteLast()
{
    if(tot == 1){
         deleteAhead();
         return;
    }
    if(root == NULL){
        printf("The queue is empty\n");
        success=0;
        return;
    }
    node *curr = root, *prev = NULL;
    while(curr->next!=NULL){
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    hold = curr->roll;
    delete(curr);
    tot--;
}

void print()
{
    node *curr = root;
    if(curr == NULL){
        cout << "No Elements.\n";
        return;
    }
    while(curr!=NULL){
        cout << curr->roll << " ";
        curr = curr->next;
    }
}

void solve(int kk)
{
    int q,aa;
    scanf("%d %d", &sz, &q);
    printf("Case %d:\n", kk);
    while(q--){
        string s1;
        cin >> s1;
        if(s1 == "pushLeft"){
            scanf("%d", &aa);
            appendAhead(aa);
            if(success) printf("Pushed in left: %d\n", aa);
        }
        else if(s1 == "pushRight"){
            scanf("%d", &aa);
            appendLast(aa);
            if(success) printf("Pushed in right: %d\n", aa);
        }
        else if(s1 == "popLeft"){
            deleteAhead();
            if(success) printf("Popped from left: %d\n", hold);
        }
        else{
            deleteLast();
            if(success) printf("Popped from right: %d\n", hold);
        }
        success=1;
    }
    delAll();
    tot=0, sz=0, hold;
    success=1, del=0;
    //print();

}

int main()
{
    //freopen("text.txt", "r", stdin);
   //fast;
   int kk=0;
   cin >> tc;
   while(++kk<=tc) solve(kk);

   return 0;
}
