//1116 Come on! Let's C（20)
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

bool isPrime(int num){
    if (num == 0 || num == 1)
    {
        return false;
    }
    for (int i = 2; i*i <= num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main(){
    int n,tmp;
    map<int,string> map;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> tmp;
        if (i == 1)
        {
            map[tmp] = "Mystery Award";
        }else if (isPrime(i))
        {
            map[tmp] = "Minion";
        }else
            map[tmp] = "Chocolate";
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        printf("%04d: ",tmp);
        if (map.count(tmp) > 0)
        {
            cout << map[tmp] << endl;
            map[tmp] = "Checked";
        }else
            cout << "Are you kidding?" << endl;
    }
    return 0;
}
