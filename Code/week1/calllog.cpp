#include<bits/stdc++.h>
using namespace std;

string cmd,sdt1,sdt2,date,time1,time2;

bool check_phone_number(string s) {
    if (s.length() != 10) return false;
    for(int i=0;i<s.length();i++){
        if(s[i]<'0' || s[i] >'9') {
            return false;
        }
    }
    return true;
}
map <string,int> numberCalls, timeCall;

int convert_time(string s) {
    return (((s[0]-'0')*10 + (s[1]-'0'))*3600 + ((s[3]-'0')*10+(s[4]-'0'))*60 + ((s[6]-'0')*10+(s[7]-'0')));
}

int count_time(string t1, string t2) {
    return convert_time(t2) - convert_time(t1);
}
int main () {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> cmd;
    int totalcall = 0;
    int incorrect = 0;
    while(cmd != "#") {
        cin >> sdt1 >> sdt2 >> date >> time1 >> time2;
        int res1 = check_phone_number(sdt1);
        int res2 = check_phone_number(sdt2);
        if(res1 == 0 || res2 == 0) {
            incorrect++;
        }
        totalcall++;
        if(res1 == 1) {
            numberCalls[sdt1]++;
            timeCall[sdt1] += count_time(time1, time2);
        }
        cin >> cmd;
    }
    cin >> cmd;
    while(cmd!="#") {
        if(cmd == "?check_phone_number") {
            if(incorrect == 0) {
                cout << 1 << endl;
            } else cout << 0 << endl;
        }
        else if(cmd == "?number_calls_from") {
            cin >> sdt1;
            cout << numberCalls[sdt1] << endl;
        }
        else if(cmd == "?number_total_calls") {
            cout << totalcall << endl;
        }
        else if(cmd == "?count_time_calls_from") {
            cin >> sdt1;
            cout << timeCall[sdt1] << endl;
        }
        cin >> cmd;
    }
    return 0;
}
