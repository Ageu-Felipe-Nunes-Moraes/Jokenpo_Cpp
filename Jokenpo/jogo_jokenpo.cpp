
#include <iostream>
#include <cstdlib> // para srand e rand
#include <ctime>   // para time
#include <chrono>  // para std::chrono::seconds
#include <thread>  // para std::this_thread::sleep_for

using namespace std;

class Jokenpo{
private:
    string escolha_maquina;
    string lista_opcoes[3] = {"PEDRA", "PAPEL", "TESOURA"};
    int escolha_pessoa, quantidade_escolhida;
    bool variavel_controle;

public:

    Jokenpo(){
        cria_linha_dupla();
        cout << "JOKENPÔ - CONTRA O COMPUTADOR" << endl;
        cria_linha_dupla();
        escolha_maquina = "";
        escolha_pessoa = 0;
        variavel_controle = true;
    }


    void tempo_delay(){
        cout << "COMPUTADOR PENSANDO..." << endl;
        int lista_quantidade_pontos[9] = {2, 3, 4, 5, 6, 7, 8, 9, 10};

        int tamanho = sizeof(lista_quantidade_pontos) / sizeof(lista_quantidade_pontos[0]); // Calcula o tamanho da lista

        // Inicializa o gerador de números aleatórios com o tempo atual
        srand(time(0));

        // Escolha aleatória de um índice dentro do intervalo válido
        int indice_aleatorio = rand() % tamanho;

        // Item escolhido aleatoriamente
        int quantidade_escolhida = lista_quantidade_pontos[indice_aleatorio];

        for (int i = 0; i < quantidade_escolhida; i++){
            float lista_segundos[5] = {0.1, 0.2, 0.3, 0.4, 0.5};
            int tamanho_segundos = sizeof(lista_segundos) / sizeof(lista_segundos[0]);
            int indice_segundo_aleatorio = rand() % tamanho_segundos;
            float segundo_escolhido = lista_quantidade_pontos[indice_segundo_aleatorio];
            this_thread::sleep_for(chrono::milliseconds(static_cast<int>(segundo_escolhido * 100))); // Converte segundos para milissegundos
            cout << ".\n" << flush;
        }
        cria_linha_dupla();
    }

    void cria_linha_dupla(){
        cout << "========================================" << endl;
    }

    void cria_linha_simples(){
        cout << "----------------------------------------" << endl;
    }

    void introducao(){;
        cout << "INSTRUCÕES DE COMO JOGAR:" << endl;
        cria_linha_simples();
        cout << "1--PEDRA" << endl;
        cout << "2--PAPEL" << endl;
        cout << "3--TESOURA" << endl;
        cout << "0--SAIR" << endl;
        cria_linha_simples();
    }

    string valor_escolha_computador(){
        int tamanho = sizeof(lista_opcoes) / sizeof(lista_opcoes[0]); // Calcula o tamanho da lista

        // Inicializa o gerador de números aleatórios com o tempo atual
        srand(time(0));

        // Escolha aleatória de um índice dentro do intervalo válido
        int indice_aleatorio = rand() % tamanho;

        // Item escolhido aleatoriamente
        string escolha = lista_opcoes[indice_aleatorio];

        return escolha;
    }

    int valor_escolha_pessoa(){
        cout << "DIGITE O NÚMERO DA SUA ESCOLHA: ";
        cin >> escolha_pessoa;
        cin.ignore();
        cria_linha_simples();
        return escolha_pessoa;
    }

    void mostra_escolhas(){
   
        while (variavel_controle){
            escolha_pessoa = valor_escolha_pessoa();
            
            if (escolha_pessoa == 0){
                cout << "FIM DE JOGO!!!" << endl;
                variavel_controle = false;
            }

            else if (escolha_pessoa > 0 && escolha_pessoa < 4){
                tempo_delay();
                escolha_maquina = valor_escolha_computador();
                cout << "HUMANO(VOCÊ): " << lista_opcoes[escolha_pessoa - 1] << endl;
                cout << "COMPUTADOR:" << escolha_maquina << endl;
                cria_linha_simples();
                verifica_vencedor();
                variavel_controle = false;
            }

            else{
                cout << "VALOR INVÁLIDO!!! TENTE NOVAMENTE!!" << endl;
                cria_linha_dupla();
            }
        }
    }

    void verifica_vencedor(){
        if (lista_opcoes[escolha_pessoa - 1] == escolha_maquina){
            cout << "EMPATE!!!" << endl;
        }

        else{
                
            if (lista_opcoes[escolha_pessoa - 1] == "PEDRA" && escolha_maquina == "TESOURA" || lista_opcoes[escolha_pessoa - 1] == "PAPEL" && escolha_maquina == "PEDRA" || lista_opcoes[escolha_pessoa - 1] == "TESOURA" && escolha_maquina == "PAPEL"){

                cout << "VOCÊ VENCEU!!!" << endl;
            }

            else if (escolha_pessoa == 0){
                cout << "" << endl;
            }    
                
            else{
                cout << "VOCÊ PERDEU" << endl;
            }
        }
        if (escolha_pessoa != 0){
            cria_linha_dupla();
            mostra_escolhas();
        }
    }        
};

int main(){
    Jokenpo iniciar_jogo;
    iniciar_jogo.introducao();
    iniciar_jogo.mostra_escolhas();
    return 0;
}
