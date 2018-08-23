//https://www.nowcoder.com/practice/6e732a9632bc4d12b442469aed7fe9ce?tpId=40&tqId=21544&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
string mid;
char pre[30],aft[30];
//已知前序中序求后序
void getAft(int sta1,int end1,int sta2,int end2,int sta3,int end3){//需要传入前序、中序、后序每次的起止点坐标
    if (sta1 > end1) {
        return ;
    }
    char root = pre[sta1];
//    int x = mid.find(root);
    int x = 0;
    while (mid[sta2+x] != root) {
        x++;
    }
    aft[end3] = root;
    
    getAft(sta1+1,sta1+x,sta2,sta2+x-1,sta3,sta3+x-1);
    getAft(sta1+x+1,end1,sta2+x+1,end2,sta3+x,end3-1);
}

//已知后序中序求前序
//void getPre(int sta1,int end1,int sta2,int end2,int sta3,int end3){//需要传入前序、中序、后序每次的起止点坐标
//    if (sta1 > end1) {
//        return ;
//    }
//    char root = aft[end3];
//    //    int x = mid.find(root);
//    int x = 0;
//    while (mid[end2-x] != root) {
//        x++;
//    }
//    pre[sta1] = root;
//    
//    getPre(end1-x+1,end1,end2-x+1,end2,end3-x,end3-1);
//    getPre(sta1+1,end1-x,sta2,end2-x-1,sta3,end3-x-1);
//}

int main(){
    while(cin >> pre){
        cin >> mid;
        int len = strlen(pre) -1;
        getAft(0,len,0,len,0,len);
        cout << aft << endl;
//        getPre(0,len,0,len,0,len);
//        cout << pre << endl;
    }
    
    
    return 0;
}
