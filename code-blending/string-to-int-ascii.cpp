/**
 * 2017-02-17
 * 문자열을 숫자로 파싱 - ASCII CODE 사용
 */
#include <iostream>

using namespace std;

int parseInt(char* str) {
    int n = 0;
    int result = 0;
    while (str[n] != '\0') {
        int diff = str[n] - 48;
        if (diff >= 0 && diff < 10) {
            result *= 10;
            result += diff;
        }
        n++;
    }
    return str[0] == '-' ? 0 - result : result;
}

int main(int argc, char** argv) {
    char* arg = argv[1];
    int parsed = parseInt(arg);
    cout << "Before : \"" << arg << "\"" << endl;
    cout << "After  :  " << parsed << endl;
    return 0;
}

