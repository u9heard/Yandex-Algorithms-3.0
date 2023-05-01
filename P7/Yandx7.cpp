#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int myAtoi(string s) {
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
        res *= 10;
        res += s[i]-48;
    }
    return res;
}

void parseTime(string &time, int &h, int &m, int &s) {

    h = myAtoi(time.substr(0, 2));
    
    m = myAtoi(time.substr(3, 2));
 
    s = myAtoi(time.substr(6, 2));
}

int mround(double d) {
    double temp = d - (int)d;
    if((double)(d - (int)d) >= 0.5) {
        d += 1 - (d - (int)d);
    }
    else {
        d -= d - (int)d;
    }
    return d;
}

long timeToSeconds(int &h, int &m, int &s) {
    long res = h * 3600 + m * 60 + s;
    return res;
}

void secondsToTime(long sec, int &h, int &m, int &s) {
    if (sec > 86400) {
        sec = sec - 86400;
    }

    h = sec / 3600;
    m = (sec - (h) * 3600)/60;
    s = (sec - (h) * 3600) - m * 60;
}

int main()
{
    string tou;
    string ser;
    string tin;

    cin >> tou >> ser >> tin;

    int h1, m1, s1;
    int h2, m2, s2;
    int h3, m3, s3;
    int hr, mr, sr;

    parseTime(tou, h1, m1, s1);
    parseTime(ser, h2, m2, s2);
    parseTime(tin, h3, m3, s3);
    int time1 = timeToSeconds(h1, m1, s1);
    int time2 = timeToSeconds(h2, m2, s2);
    int time3 = timeToSeconds(h3, m3, s3);
    int dTime = time3 - time1;
    if (dTime < 0) {
        
        secondsToTime(time2 + (mround((double)(time3 - time1+86400) / 2)), hr, mr, sr);
    }
    else {
        secondsToTime(time2 + (mround((double)(time3 - time1) / 2)), hr, mr, sr);
    }

    printf("%02d:%02d:%02d", hr, mr, sr);

    return 0;

}
