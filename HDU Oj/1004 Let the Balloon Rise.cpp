//  1004 Let the Balloon Rise
#include <iostream>
using namespace std;

int main(){
    int n,count=0,max;
    string index;
    string ballon[1001];
    while(cin >> n){
        if(!n)
            break;
        for (int i=0;i<n;i++){
            cin >> ballon[i];
        }
        index = ballon[0];
        max = 0;
        count = 0;
        for (int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(ballon[i] == ballon[j])
                    count++;
            }
            if(count > max){
                max = count;
                index = ballon[i];
            }
        }
        cout << index <<endl;
    }
    return 0;
    }
