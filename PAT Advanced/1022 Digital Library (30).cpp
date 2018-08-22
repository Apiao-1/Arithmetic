////1022 Digital Library (30) https://pintia.cn/problem-sets/994805342720868352/problems/994805480801550336
//#include <iostream>
//#include <string>
//#include <fstream>
//#include <vector>
//#include <sstream>
//#include <algorithm>
//using namespace std;
//
//struct book
//{
//    string ID;
//    string title;
//    string author;
//    vector<string> keywords;
//    string publisher;
//    string year;
//};
//
//vector<string> SearchSystem(const vector<struct book> & v, string query)
//{
//    vector<string> rlt;
//    if (query.size() == 0)
//    {
//        return rlt;
//    }
//    string year;
//    string queryAvil = query.substr(3);//截取获得的字符串
//    switch (query[0])
//    {
//        case '1'://title
//            for (int i = 0; i < v.size(); i++)
//            {
//                if (queryAvil == v[i].title)
//                    rlt.push_back(v[i].ID);
//            }
//            break;
//        case '2'://author
//            for (int i = 0; i < v.size(); i++)
//            {
//                if (queryAvil == v[i].author)
//                    rlt.push_back(v[i].ID);
//            }
//            break;
//        case '3'://keywords
//            for (int i = 0; i < v.size(); i++)
//            {
//                for (int j = 0; j < v[i].keywords.size(); j++)
//                {
//                    if (queryAvil == v[i].keywords[j])
//                    {
//                        rlt.push_back(v[i].ID);
//                    }
//                }
//            }
//            break;
//        case '4':// publisher
//            for (int i = 0; i < v.size(); i++)
//            {
//                if (queryAvil == v[i].publisher)
//                    rlt.push_back(v[i].ID);
//            }
//            break;
//        case '5':// year
//            for (int i = 0; i < v.size(); i++)
//            {
//                if (queryAvil == v[i].year)
//                    rlt.push_back(v[i].ID);
//            }
//            break;
//        default:
//            break;
//    }
//    if (rlt.size() == 0)
//    {
//        rlt.push_back("Not Found");
//    }
//    return rlt;
//}
//
//bool Cmp(struct book & a, struct book & b)
//{
//    return a.ID < b.ID;
//}
//
//int main()
//{
//    int N,M;
//    //ifstream cin("test.txt");
//    while (cin >> N)
//    {
//        vector<struct book> bookDatabase(N);
//        for (int i = 0; i < N; i++)
//        {
//            cin >> bookDatabase[i].ID;
//            char c = getchar();
//            //cin.get();
//            getline(cin, bookDatabase[i].title);
//            getline(cin, bookDatabase[i].author);
//            string tmp;
//            string temp;
//            getline(cin, tmp);
//            for (int j = 0; tmp[j] != '\0'; j++)
//            {
//                if(tmp[j]!=' ')
//                    temp += tmp[j];
//                if (j < tmp.size() && (tmp[j+1] == ' ' || tmp[j+1] == '\0' ))
//                {
//                    bookDatabase[i].keywords.push_back(temp);
//                    temp = "";
//                }
//            }
//            getline(cin, bookDatabase[i].publisher);
//            cin >> bookDatabase[i].year;
//        }
//        sort(bookDatabase.begin(), bookDatabase.end(), Cmp);
//        cin >> M;
//        char c = getchar();
//        //cin.get();
//
//        string query;
//        for (int i = 0; i < M; i++)
//        {
//            getline(cin, query);
//            vector<string> rlt = SearchSystem(bookDatabase, query);
//            cout << query << endl;
//            for (int j = 0; j < rlt.size(); j++)
//            {
//                cout << rlt[j] << endl;
//            }
//        }
//    }
//    system("pause");
//}
#include <iostream>
#include <map>
#include <set>
using namespace std;
map<string, set<int> > title, author, key, pub, year;
void query(map<string, set<int> > &m, string &str) {
    if(m.find(str) != m.end()) {
        for(auto it = m[str].begin(); it != m[str].end(); it++)
            printf("%07d\n", *it);
    } else
        cout << "Not Found\n";
}
int main() {
    int n, m, id, num;
    scanf("%d", &n);
    string ttitle, tauthor, tkey, tpub, tyear;
    for(int i = 0; i < n; i++) {
        scanf("%d\n", &id);
        getline(cin, ttitle);
        title[ttitle].insert(id);
        getline(cin, tauthor);
        author[tauthor].insert(id);
        while(cin >> tkey) {
            key[tkey].insert(id);
            char c = getchar();
            if(c == '\n') break;
        }
        getline(cin, tpub);
        pub[tpub].insert(id);
        getline(cin, tyear);
        year[tyear].insert(id);
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d: ", &num);
        string temp;
        getline(cin, temp);
        cout << num << ": " << temp << "\n";
        if(num == 1) query(title, temp);
        else if(num == 2) query(author, temp);
        else if(num == 3) query(key, temp);
        else if(num == 4) query(pub,temp);
        else if(num ==5) query(year, temp);
    }
    return 0;
}
