/**
 * 2017-02-17
 * 문자열을 숫자로 파싱 - ASCII CODE 사용
 */
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    int n = 0;
    int result = 0;
    while (argv[1][n] != '\0') {
        int diff = argv[1][n] - 48;
        if (diff >= 0 && diff < 10) {
            result *= 10;
            result += diff;
        }
         
        n++;
    }
    if (argv[1][0] == '-') result *= -1;
    cout << result << endl;
    return 0;
}

