//1147 Heaps（30)
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <cstdio>
using namespace std;
int a[1010];
int n,m,ind,heap,flag;

void postOrder(int s){
    if(s > m) return ;
    postOrder(2*s);
    postOrder(2*s+1);
    if(flag){
        cout << a[s];
        flag = 0;
    }else
        cout << " " << a[s];
}


int main()
{
    cin >> n>> m;
    for(int i = 0; i<n; i++)
    {
        fill(a,a+1010,0);
        for(int j = 1; j<=m; j++)
        {
            cin >> a[j];
        }
        heap = a[1] >= a[2]? 1:2; //1表示大顶堆，2表示小顶堆
        for(int j = 1; 2*j<=m; j++)
        {
            ind = 2*j;
            if(heap == 1)
            {
                if(ind+1 <= m && a[ind] < a[ind+1])ind++;
                if(a[j] < a[ind])
                {
                    heap = 0;
                    break;
                }
            }
            else if(heap == 2)
            {
                if(ind+1 <= m && a[ind] >= a[ind+1])ind++;
                if(a[j] > a[ind])
                {
                    heap = 0;
                    break;
                }
            }
        }
        if(heap == 0) cout << "Not Heap" << endl;
        else if(heap == 1) cout << "Max Heap" << endl;
        else if(heap == 2) cout << "Min Heap"<<endl;
        flag = 1;
        postOrder(1);
        cout << endl;
    }
    
    return 0;
}
