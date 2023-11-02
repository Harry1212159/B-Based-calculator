#include "SoNguyenLon.h"
SoNguyenLon::SoNguyenLon(long long n){
    if (n == 0) bigInt.push_back(0);
    else {
        for (; n > 0; n /= 10)
            bigInt.push_back(n % 10);
    }
}
SoNguyenLon::SoNguyenLon(int n, int size){
    if (n == 0) bigInt.push_back(0);
    else {
        for (int i = 0; i < size; i++)
            bigInt.push_back(n);
    }
}

int SoNguyenLon::charToInt(char c){
    if(c >= '0' && c <= '9')
        return c - '0';
    else if(c >= 'A' && c <= 'Z')
        return c - 'A' + 10;
    else    
        return -1;
}

char SoNguyenLon::intToChar(int n){
    if(n >= '0' && n <= '9')
        return '0' + n;
    else
        return n + 'A' - 10;
}

bool SoNguyenLon::operator > (SoNguyenLon n){
    if(bigInt.size() != n.bigInt.size()) 
        return bigInt.size() > n.bigInt.size();
    for (int i = bigInt.size() - 1; i >= 0; i--)
        if (bigInt[i] != n.bigInt[i]) 
            return bigInt[i] > n.bigInt[i];
    return false;
}

SoNguyenLon SoNguyenLon::operator + (SoNguyenLon& s1){
    SoNguyenLon kq;
    kq.bigInt.clear();
    int mem = 0;
    vector<int> &a = bigInt;
    vector<int> &b = s1.bigInt;
    for(int i = 0; i < a.size() || i < b.size(); i++){
        if(i < a.size()) mem += a[i];
        if(i < b.size()) mem += b[i];
        kq.bigInt.push_back(mem % 10);
        mem /= 10;
    }
    if (mem) kq.bigInt.push_back(mem);
    if(kq > MAXINT) MAXINT = kq;
    return kq;
}

SoNguyenLon SoNguyenLon::operator + (long long n){
    SoNguyenLon temp(n);
    return *this + temp;
}

SoNguyenLon SoNguyenLon::operator - (SoNguyenLon& s1){
    SoNguyenLon kq;
    kq.bigInt.clear();
    int mem = 0;
    if(s1 > *this) return SoNguyenLon(0);
    vector<int> &a = bigInt;
    vector<int> &b = s1.bigInt;
    for(int i = 0; i < a.size(); i++){
        int temp = a[i] - mem;
        if(i < b.size()) temp -= b[i];
        if(temp < 0) temp += 10, mem = 1; 
        else mem = 0;
        kq.bigInt.push_back(temp); 
    }
    while (kq.bigInt.back() == 0) kq.bigInt.pop_back();
    return kq;
}
SoNguyenLon SoNguyenLon::operator - (long long n){
    SoNguyenLon temp(n);
    return *this - temp;
}

SoNguyenLon operator + (long long n, SoNguyenLon& s){
    SoNguyenLon temp(n);
    return s + temp;
}
SoNguyenLon operator - (long long n, SoNguyenLon& s){
    SoNguyenLon temp(n);
    return temp - s;
}
ostream& operator << (ostream& os, const SoNguyenLon& s){
    for(int i = s.bigInt.size() - 1; i >=0; i--){
        os << s.bigInt[i];
    }
    return os;
}
SoNguyenLon SoNguyenLon::SNLMax(){
    return MAXINT;
}
