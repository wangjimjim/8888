#include <iostream>
#include <cstring>
using namespace std;

const int MAX_LEN = 35;  // �Ʀr�̤j���סA�ݭn�[1��s�x'\0'
char a[MAX_LEN], b[MAX_LEN];  // �s�x��J����Ӥj���
int ans[MAX_LEN];  // �s�x�p�⵲�G�A�qans[0]�}�l�s�x�A�C��s�x�bans[0]�A����s�x�bans[len-1]
int lena, lenb, len;  // ���O��a�Bb�Bans������

int main() {
    int n;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        lena = strlen(a);
        lenb = strlen(b);
        len = max(lena, lenb);  // ����J����Ӥj��ƪ��̤j����
        memset(ans, 0, sizeof(ans));  // �N�p�⵲�Gans�M�s

        // �v��ۥ[�A�q�C��찪��
        for (int i = 0; i < len; i++) {
            int numa = (i < lena) ? (a[lena - 1 - i] - '0') : 0;  // ��a����e��ơA���s�b�ɬ�0
            int numb = (i < lenb) ? (b[lenb - 1 - i] - '0') : 0;  // ��b����e��ơA���s�b�ɬ�0
            ans[i] = ans[i] + numa + numb;  // �i��
            if (ans[i] >= 10) {  // �i��
                ans[i] -= 10;
                ans[i + 1]++;
            }
        }

        // ��X���G�A�q�����C��
        if (ans[len] > 0) {  // �p�G�̰��즳�i��A�h�n��X
            len++;
        }
        for (int i = len - 1; i >= 0; i--) {
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}

