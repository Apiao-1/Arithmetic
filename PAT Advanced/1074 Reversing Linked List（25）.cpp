//1074 Reversing Linked List（25）https://pintia.cn/problem-sets/994805342720868352/problems/994805394512134144
//注意：不一定所有的输入的结点都是有用的，加个计数器sum

//一组案例通不过，找不到错误，24分
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//vector<struct node> vec,ans;
//struct node{
//    int val;
//    int next,now;
//}list[100001],real[100001];
//
//int main(){
//    int tmp,n,k,start;
//    scanf("%d%d%d",&start,&n,&k);
//    for (int i = 0; i<n; i++) {
//        scanf("%d",&tmp);
//        list[tmp].now = tmp;
//        scanf("%d%d",&list[tmp].val,&list[tmp].next);
//    }
//    tmp = start;
//    int cnt = 0;
//    while (tmp != -1) {
//        real[cnt++] = list[tmp];
//        tmp = list[tmp].next;
//    }
//    tmp = start;
//    int time = cnt/k;
//    while (time >= 0) {
//        vec.clear();
//        for (int i = 0; i<k; i++) {
//            if (tmp == -1) {
//                break;
//            }
//            vec.push_back(list[tmp]);
//            tmp = list[tmp].next;
//        }
//        if (time > 0) {
//            reverse(vec.begin(), vec.end());
//        }
//        if (time == n/k) {
//            printf("%05d %d",vec[0].now,vec[0].val);
//            for (int i = 1; i<vec.size(); i++) {
//                printf(" %05d %d %05d\n",vec[i].now,vec[i].now,vec[i].val);
//            }
//        }else{
//            for (int i = 0; i<vec.size(); i++) {
//                printf(" %05d\n%05d %d",vec[i].now,vec[i].now,vec[i].val);
//            }
//        }
//        time--;
//    }
//    printf(" -1\n");
//    return 0;
//}

#include<cstdio>
#include<stack>
#include<iostream>
using namespace std;
struct Node {
    int now;
    int data;
    int next;
}node[1000010],tp[1000010],prt[1000010],t;
int main() {
    int fstad, K, N;
    scanf("%d%d%d", &fstad, &N, &K);
    int temp;
    for (int i = 0; i < N; i++) {
        scanf("%d", &temp);
        node[temp].now = temp;
        scanf("%d%d",&node[temp].data, &node[temp].next);
    }
    t = node[fstad];
    int cnt = 1;
    tp[0] = t;
    while (t.next!= -1) {
        tp[cnt++] = node[t.next];
        t = node[t.next];
    }
    int length = cnt;
    stack<Node> st;
    cnt = 0;
    for (int i = 0; i+K <=length; i+=K) {
        for (int j = i; j < i + K; j++) {
            st.push(tp[j]);
        }
        while (!st.empty()) {
            prt[cnt++] = st.top();
            st.pop();
        }
    }
    for (int i = cnt; i < length; i++) {
        prt[i] = tp[i];
    }
    for (int i = 0; i < length-1; i++) {
        prt[i].next = prt[i + 1].now;
    }
    prt[length- 1].next = -1;
    for (int i = 0; i <length; i++) {
        if(i<length-1)
            printf("%05d %d %05d\n", prt[i].now, prt[i].data, prt[i].next);
        else
            printf("%05d %d %d", prt[i].now, prt[i].data, prt[i].next);
    }
}
