#include <iostream>
#include <vector>
using namespace std;
class SoNguyenLon{
    private:
        vector <int> bigInt;
        static SoNguyenLon MAXINT;
        int b;
    public:
        SoNguyenLon(long long n = 0);
        SoNguyenLon(int a, int size);
        bool operator > (SoNguyenLon n);
        int charToInt(char c);
        char intToChar(int n);
        SoNguyenLon operator + (SoNguyenLon& s1);
        SoNguyenLon operator + (long long n);
        SoNguyenLon operator - (SoNguyenLon& s1);
        SoNguyenLon operator - (long long n);

        friend ostream& operator << (ostream& os, const SoNguyenLon& s);
        friend SoNguyenLon operator + (long long n,SoNguyenLon& s);
        friend SoNguyenLon operator - (long long n,SoNguyenLon& s);
        static SoNguyenLon SNLMax();
};

SoNguyenLon SoNguyenLon::MAXINT(0);