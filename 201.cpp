#include <string>
#include <iostream>

using namespace std;

int charToInt(char c, int B){
    int res = -1;
    if(c >= '0' && c <= '9')
        return c - '0';
    else if(c >= 'A' && c <= 'Z')
        return c - 'A' + 10;
    if (res >= 0 && res < B) return res;
    throw::invalid_argument("Not an int in base B");
    return -1;
}

string addToBaseB(string s1, string s2, int B){
    string result = "";
    int carry = 0;
    int len1 = s1.length();
    int len2 = s2.length();
    int maxLen = max(len1, len2);
    for(int i = 0; i < maxLen; i++){
        int val1 = (i < len1) ? charToInt(s1[len1 - i - 1], B) : 0;
        int val2 = (i < len2) ? charToInt(s2[len2 - i - 1], B) : 0;
        int sum = val1 + val2 + carry;
        carry = sum / B;
        sum = sum % B;
        result = char(sum + '0') + result;
    }

    if (carry > 0) {
        result = char(carry + '0') + result;
    }
    return result;
}

bool isGreater(const std::string& s1, const std::string& s2) {
    int len1 = s1.length();
    int len2 = s2.length();

    if (len1 < len2) {
        return false;
    } else if (len1 > len2) {
        return true;
    }

    for (int i = 0; i < len1; ++i) {
        if (s1[i] < s2[i]) {
            return false;
        } else if (s1[i] > s2[i]) {
            return true;
        }
    }
    return false;
}

string subtractToBaseB(string s1, string s2, int B){
    string result = "";
    if(!isGreater(s1, s2)) return "-" + subtractToBaseB(s2, s1, B);
    int carry = 0;
    int len1 = s1.length();
    int len2 = s2.length();
    int maxLen = max(len1, len2);
    int borrow = 0;
    for (int i = 0; i < maxLen; i++) {
        int value1 = (i < len1) ? charToInt(s1[len1 - i - 1], B) : 0;
        int value2 = (i < len2) ? charToInt(s2[len2 - i - 1], B) : 0;
        value1 -= borrow;

        if (value1 < value2) {
            value1 += B;
            borrow = 1;
        } else {
            borrow = 0;
        }

        int diff = value1 - value2;
        char ch = char(diff + '0');
        result = ch + result;
    }

    while (result.length() > 1 && result[0] == '0') {
        result = result.substr(1);
    }
    return result;
}
int main(){
    int B;
    string X, Y;

    cout << "Enter base (2-36): ";
    cin >> B;
    cin.ignore();

    if (B < 2 || B > 36) {
        cout << "Invalid base. Please enter a valid base between 2 and 36." << endl;
        return 1;
    }

    cout << "Enter first number X in base " << B << " (X >= 0): ";
    cin >> X;
    
    cout << "Enter second number Y in base " << B << " (Y >= 0): ";
    cin >> Y;
    
    string sum = addToBaseB(X, Y, B);
    string difference = subtractToBaseB(X, Y, B);
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << difference << endl;
    return 0;
}