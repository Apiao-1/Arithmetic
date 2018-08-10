//https://www.nowcoder.com/practice/7d348aa8b7d24e01a4f10bd023e2fb54?tpId=40&tqId=21548&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <math.h>
#include <climits>
#include <vector>
using namespace std;

struct node{
    int val;
    struct node *next;
} *list = new node;//创建一个列表指针并为其分配空间

void insert(int val){
    node *n = new node;
    n->val = val;
    n->next = NULL;
    if(list -> next !=NULL){
        int flag = 0;
        node *p = list->next;
        node *pre = list;
        while (p != NULL) {
            if ( n->val < p->val ) {
                pre->next = n;
                n->next = p;
                flag = 1;
                break;
            }
            pre = p;
            p = p->next;
        }
        if (!flag) {
            pre -> next = n;
        }
    }else
        list -> next =  n;
    
}


int main(){
    int n,val;
    while (cin >>n) {
        for (int i = 0; i<n; i++) {
            cin >> val;
            insert(val);
        }
        struct node *start = list -> next;
        cout << start -> val;
        start = start ->next;
        while (start) {
            cout << " " << start->val;
            start = start ->next;
        }
    }
    return 0;
}
