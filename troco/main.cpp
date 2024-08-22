#include <iostream>
#include <set>
#include <vector>
#include <limits>
using namespace std;

//const int INF =  std::numeric_limits<int>::max();

const int INF = 1e9;

// {1,3,4}

int solucao(set<int>& moedas,int troco, vector<int>& resposta){
    
    for(int i : moedas){
        if(troco - i < 0){
            return 0;
        }
        if(troco - i == 0){
            return 1;
        }
        else{
            troco -= i;
            if(solucao(moedas,troco,resposta) == 1) {
                resposta.push_back(i);
                return 1;
            } else {
                return 0;
            }
        }
    }
}


int solucaoCerta(set<int>& moedas, vector<int> troco){
    bool condiciona = true;
    int resposta = 0;
    vector<int> trocado;
    while (condiciona) {
        trocado.clear();
        resposta++;
        for (int i : troco) {
            for (int j: moedas) {
                int x = i - j;
                if (x == 0) {condiciona = false;}
                if (x > 0) {
                    trocado.push_back(x);
                }
            }
        }
        troco.assign(trocado.begin(), trocado.end());
    }
    return resposta;
}


int solve(set<int> moedas, int x) {
    if (x < 0) { return INF;}
    if (x == 0) { return 0;}
    int best = INF;
    for (auto moeda: moedas) {
        best = min(best, solve(moedas, x - moeda) + 1);
    }
    return best;
}

int solveMEMO(set<int> moedas, int x, vector<bool> &ready, vector<int> &value) {
    if (x < 0) { return INF;}
    if (x == 0) { return 0;}
    if (ready[x]) {return value[x];}
    int best = INF;
    for (auto moeda: moedas) {
        best = min(best, solveMEMO(moedas, x - moeda, ready, value) + 1);
    }
    ready[x] = true;
    value[x] = best;
    return best;
}

int main(void){
    set<int> moedas = {1, 3, 4};
    int troco = 100000;
    //vector<int> trocado = {troco};

    vector<bool> ready(troco, false);
    vector<int> value(troco, 0);

    cout << solveMEMO(moedas,troco, ready, value);
    
    return 0;
}