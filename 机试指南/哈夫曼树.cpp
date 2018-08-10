//https://www.nowcoder.com/practice/162753046d5f47c7aac01a5b2fcda155?tpId=40&tqId=21520&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#include <iostream>
#include <string>
#include <cstdio>
#include <queue>
using namespace std;

int main(){
    int n,w[1002],sum,n1,n2;
    priority_queue<int, vector<int>, greater<int>> huff;//小顶堆构造Huffman tree
    while (cin >> n) {
        sum = 0;
        for (int i = 0; i<n; i++) {
            cin >> w[i];
            huff.push(w[i]);
        }
        while (huff.size()>1) {
            n1 = huff.top();
            huff.pop();
            n2 = huff.top();
            huff.pop();
            sum += n1 + n2;
            huff.push(n1 + n2);
        }
        cout << sum <<endl;

    }
    
    return 0;
}
