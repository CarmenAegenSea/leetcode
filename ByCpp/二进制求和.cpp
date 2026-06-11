#include <string>
#include <algorithm>

using namespace std;

string addBinary(string a, string b) {
    string result;
    int i = a.length() - 1;
    int j = b.length() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry > 0) {
        int bitA = (i >= 0) ? a[i--] - '0' : 0;
        int bitB = (j >= 0) ? b[j--] - '0' : 0;

        int sum = bitA + bitB + carry;
        carry = sum / 2;
        result += (sum % 2) + '0';
    }

    reverse(result.begin(), result.end());
    return result;
}
