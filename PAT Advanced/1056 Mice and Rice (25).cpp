//1056 Mice and Rice (25) https://pintia.cn/problem-sets/994805342720868352/problems/994805419468242944
/*/
 题意梗概
 1）input中的第三行是索引，表示的是以第三行索引的顺序进行比较，也就是说第6、0、8个mice先组成一组进行比较，而这3个mice吃到的rice就是第二行中对应的值19、25、57，因此第8个mice吃到的是57数量最多晋级，同理第7、10、5个mice吃到的rice是22、10、3，第7个晋级，第9、1、4个mice吃到的rice是56、18、37，第9个晋级，剩下的只有第2、3个mice，分别吃到的rice是0、46，第3个晋级，于是第8、7、9、3一共4个mice晋级到下一轮，并继续按照这个顺序比较，那么其他没有晋级的mice的排名都是第5名。
 2）第8、7、9、3个mice吃到的rice分别是57、22、56、46，前三个中第8个晋级，剩下的第3个也晋级，所以未晋级的7、9的排名都是第3。
 3）第8、3个mice的排名分别是第1和第2了。
 /*/

#include <iostream>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

struct mice{
    int id;
    int rank;
}mice[1001];

bool cmp(struct mice a,struct mice b){
    return a.rank > b.rank;
}

int main() {
    int n,group;
    cin >> n >> group;
    int num = n;
    int food[n],rank[n],i,tmp;
    queue<int> seq;
    fill(rank, rank+n, 0);
    for (int i = 0; i<n; i++) {
        cin >> food[i];
    }
    for (int i = 0; i<n; i++) {
        cin >> tmp;
        seq.push(tmp);
    }
    int maxMice = seq.front();
    int allRound = 1;
    while (n > 1) {
        int flag = 0;
        for (i = 0; i<n; i++) {
            tmp = seq.front();
            seq.pop();
            if (food[tmp] > food[maxMice]) {
                maxMice = tmp;
            }
            if ((i+1) % group == 0) {
                seq.push(maxMice);
                rank[maxMice]++;
                maxMice = seq.front();
            }
        }
        if (n % group > 0) {
            seq.push(maxMice);
            rank[maxMice]++;
            maxMice = seq.front();
            flag = 1;
        }
        n /= group;
        n += flag;
        allRound++;
    }
    for (i = 0; i<num; i++) {
        mice[i].id = i;
        mice[i].rank = rank[i];
    }
    sort(mice, mice+num,cmp);
    int index = 1;
    for (i = 0; i<num; i++) {
        rank[mice[i].id] = index;
        if (i > 0 && mice[i].rank == mice[i-1].rank) {
            rank[mice[i].id] = rank[mice[i-1].id];
        }
        index++;
    }
    for (i = 0; i<num-1; i++) {
        printf("%d " ,rank[i]);
    }
    printf("%d\n" ,rank[i]);
    return 0;
}
