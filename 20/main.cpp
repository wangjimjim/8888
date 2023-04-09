#include <iostream>
#include <cstring>
using namespace std;

const int MAX_LEN = 35;  // 數字最大長度，需要加1位存儲'\0'
char a[MAX_LEN], b[MAX_LEN];  // 存儲輸入的兩個大整數
int ans[MAX_LEN];  // 存儲計算結果，從ans[0]開始存儲，低位存儲在ans[0]，高位存儲在ans[len-1]
int lena, lenb, len;  // 分別為a、b、ans的長度

int main() {
    int n;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        lena = strlen(a);
        lenb = strlen(b);
        len = max(lena, lenb);  // 取輸入的兩個大整數的最大長度
        memset(ans, 0, sizeof(ans));  // 將計算結果ans清零

        // 逐位相加，從低位到高位
        for (int i = 0; i < len; i++) {
            int numa = (i < lena) ? (a[lena - 1 - i] - '0') : 0;  // 取a的當前位數，不存在時為0
            int numb = (i < lenb) ? (b[lenb - 1 - i] - '0') : 0;  // 取b的當前位數，不存在時為0
            ans[i] = ans[i] + numa + numb;  // 進位
            if (ans[i] >= 10) {  // 進位
                ans[i] -= 10;
                ans[i + 1]++;
            }
        }

        // 輸出結果，從高位到低位
        if (ans[len] > 0) {  // 如果最高位有進位，則要輸出
            len++;
        }
        for (int i = len - 1; i >= 0; i--) {
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}

