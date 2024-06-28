#include <iostream>
#include <string>

using namespace std;

struct Pessoa{
    string nome;
};

int main(){

    int tamanho_fila = 10;
    Pessoa fila[tamanho_fila];
    int posicaoAtual = -1;
    char comando;

    while(cin >> comando && comando != 'p'){
        if(comando == '+'){// adiciona
            Pessoa pessoa;
            cin >> pessoa.nome;
            if(posicaoAtual + 1 >= tamanho_fila){
                cout << "Fila esta cheia" << endl;
            } else{
                cout << pessoa.nome << " entrou na fila" << endl;
                fila[++posicaoAtual] = pessoa;
            }
        } else if(comando == '-'){ // remover
            if(posicaoAtual == -1){
                cout << "Fila esta vazia" << endl;
            } else{
                string desistente;
                int posicao_desistente = -1;
                cin >> desistente;
                for(int i = 0; i <= posicaoAtual; i++){
                    if(fila[i].nome == desistente){
                        posicao_desistente = i;
                        break;
                    }
                }
                if(posicao_desistente == -1){
                    cout << "Pesso não encontrada na fila" << endl;
                } else{
                    for(int i = posicao_desistente; i < posicaoAtual; i++){
                    fila[i] = fila[i+1];
                    }
                    cout << desistente << " saiu da fila" << endl;
                    --posicaoAtual;
                }
            }
        } else if(comando == 'a'){ // atender
            if(posicaoAtual == -1){
                cout << "Fila esta vazia" << endl;
            } else{
                cout << "Atendeu: " << fila[0].nome << endl;;
                for(int i = 0; i < posicaoAtual; i++){
                    fila[i] = fila[i+1];
                }
                --posicaoAtual;
            }
        } else{
            cout << "Comando invalido" << endl;
        }
    }
    
    return 0;

}