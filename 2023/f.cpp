#include <iostream>
#include <queue>

using namespace std;

int main(void) {
    int D, C, R;
    cin >> D; // disposição inicial
    cin >> C; // atividas cançadas
    cin >> R; // atividas revigora
    queue<int> atividades_C;
    queue<int> atividades_R;

    for (int i = 0; i < C; i++) {
        int x;
        cin >> x;
        atividades_C.push(x);
    }

    for (int i = 0; i < R; i++) {
        int x;
        cin >> x;
        atividades_R.push(x);
    }

    int sum = 0;

    while (!atividades_C.empty() || !atividades_R.empty()) {
        int canca = atividades_C.front();
        if ((D < canca) && atividades_R.empty()) {break;}
        if (D > canca) {
            D = D-canca;
            atividades_C.pop();
            sum++;
        } else {
            D = D + atividades_R.front();
            atividades_R.pop();
            sum++;
        }
   }
    cout << sum;

    return 0;
}