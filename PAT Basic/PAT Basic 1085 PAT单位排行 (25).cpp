////PAT Basic 1085 PAT单位排行 (25)
//
//#include <iostream>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//struct student{
//    string id;
//    int score;
//    string school;
//    bool flag;
//};
//struct rankList{
//    string school;
//    int sumScore;
//    int num;
//};
//
//string changeLow(string src){
//    transform(src.begin(), src.end(), src.begin(), ::tolower);
//    return src;
//}
//bool compare(rankList a,rankList b){
//    if (a.sumScore != b.sumScore) return a.sumScore > b.sumScore; //按sumScore降序
//    if (a.num != b.num) return a.num < b.num;//按num升序
//    return a.school < b.school;//按字典序
//}
//
//int main(){
//    int n,index,flag,a,j,length;
//    string rowInput;
//    while(cin >> n){
//        a = 0;
//        length = 0;
//        student s[n];
//        rankList rank[n];
//        //初始化
//        for(int i=0;i<n;i++){
//            rank[i].num = 0;
//            rank[i].sumScore =0;
//            rank[i].school = "";
//        }
//        //学生信息输入
//        for(int i=0;i<n;i++){
//            flag =1;
//            cin >> s[i].id;
//            cin >> s[i].score;
//            cin >> rowInput;
//            s[i].school = changeLow(rowInput);
//            s[i].flag = 1;
//            //获取unique的学校加入rank中
//            for(j=0;j<=i;j++){
//                if (rank[j].school == s[i].school){flag = 0;break;}
//            }
//            if (flag){
//                rank[length].school = s[i].school;
//                length++;
//                //                cout << rank[j].school <<endl;
//            }
//        }
//        for(a=0;a<length;a++){
//            //            cout << rank[a].school<<endl;
////                        for(int i=0;(s[i].flag) && (i<n);i++){
//            for(int i=0;i<n;i++){
//                //                cout <<i <<endl;
//                if (s[i].school == rank[a].school){
//                    rank[a].num++;
//                    s[i].flag = 0;
//                    if (s[i].id[0] == 'A')
//                        rank[a].sumScore += s[i].score;
//                    else if (s[i].id[0] == 'B')
//                        rank[a].sumScore += s[i].score/1.5;
//                    else if (s[i].id[0] == 'T')
//                        rank[a].sumScore += s[i].score*1.5;
//                }
//                //                cout <<"flag： " << s[i].flag <<endl;
//            }
//        }
//        sort(rank,rank+length,compare);//排序
//        index = 1;
//        flag = 0;
//        cout << length<<endl;
//        for(int i=0;i<length;i++){
//            cout << index << " ";
//            cout <<rank[i].school << " ";
//            cout <<rank[i].sumScore << " ";
//            cout <<rank[i].num <<endl;
//            index++;
//            if (flag)
//            {index++;flag = 0;}
//            if (rank[i].sumScore == rank[i+1].sumScore)
//            {index--;flag = 1;}
//            
//        }
//    }
//}


#include <iostream>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

struct node{
    string school;
    int score;
    int num;
};

string changeLow(string school){
    transform(school.begin(), school.end(), school.begin(), ::tolower);
    return school;
}

bool compare(node a, node b){
    if (a.score != b.score)
        return a.score > b.score;
    else if (a.num != b.num)
        return a.num < b.num;
    else
        return a.school<b.school;
}

int main(){
    int n;
    map<string,double> sum;
    map<string,int>num;
    while (cin >> n) {
        string license,school;
        double score;
        for (int i=0;i<n;i++){
            cin >> license;
            cin >> score;
            cin >> school;
            school = changeLow(school);
            if (license[0] == 'B')
                score /= 1.5;
            else if (license[0] == 'T')
                score *=1.5;
            sum[school] += score;
            num[school] ++;
        }
        vector<node> ans;
        for(auto i = sum.begin();i!=sum.end();i++){
            ans.push_back(node{i -> first,int(sum[i->first]),num[i->first]});
        }
        sort(ans.begin(),ans.end(),compare);
        int rank;
        for(int i=0;i < ans.size();i++){
            rank =i+1;
            if(ans[i].score == ans[i-1].score)
                rank = i;
            cout << rank << " " << ans[i].school << " " <<ans[i].score<< " " << ans[i].num <<endl;
            
        }
    }
    
    return 0;
}
