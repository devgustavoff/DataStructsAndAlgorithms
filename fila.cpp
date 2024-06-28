#include <iostream>
#include <string>

using namespace std;

struct Pessoa{
    string nome;
};

// adiciona 
void adiciona(Pessoa pessoa, Pessoa fila[], int& posicao_Atual, int tamanho_Fila){
    if(posicao_Atual + 1 >= tamanho_Fila){
        cout << "Fila esta cheia" << endl;
        return;
    } else{
        fila[++posicao_Atual] = pessoa;
        cout << pessoa.nome << " entrou na fila" << endl;
        return;
    }
}

// remove
void remove(int& posicao_Atual, string desistente, Pessoa fila[]){
    if(posicao_Atual == -1){
        cout << "Fila esta vazia" << endl;
        return;
    } else{
        int id = -1;
        for(int i = 0; i <= posicao_Atual; i++){
            if(fila[i].nome == desistente){
                id = i;
                break;
            }
        }
        if(id == -1){
            cout << "Essa pessoa não esta na fila" << endl;
            return;
        } else{
            cout << desistente << " saiu da fila" << endl;
            for(int i = id; i < posicao_Atual; i++){
                fila[i] = fila[i+1];
            }
            --posicao_Atual;
        }
    }
}

// atendendo
void atende(Pessoa fila[], int& posicao_Atual){
    if(posicao_Atual == -1){
        cout << "Fila esta vazia" << endl;
        return;
    } else{
        cout << "Atendeu: " << fila[0].nome << endl;
        for(int i = 0; i < posicao_Atual; i ++){
            fila[i] = fila[i+1];
        }
        --posicao_Atual;
    }
}

int main(){

    int tamanho_fila = 10;
    Pessoa fila[tamanho_fila];
    int posicaoAtual = -1;
    char comando;
    Pessoa pessoa;


    while(cin >> comando && comando != 'p'){
        switch(comando){
            
            case '+': // adiciona
            {
                cin >> pessoa.nome;
                adiciona(pessoa, fila, posicaoAtual, tamanho_fila);
                break;
            }

            case '-': // remove
            {
                string desistente;
                cin >> desistente;
                remove(posicaoAtual, desistente, fila);
                break;
            }

            case 'a': // atende
            {
                atende(fila, posicaoAtual);
                break;
            }       
        }   
    }
    
    return 0;

}