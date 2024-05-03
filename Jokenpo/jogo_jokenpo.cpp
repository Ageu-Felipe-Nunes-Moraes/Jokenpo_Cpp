
#include <iostream>
#include <cstdlib> // para srand e rand
#include <ctime>   // para time
#include <chrono>  // para std::chrono::seconds
#include <thread>  // para std::this_thread::sleep_for

using namespace std;

class Jokenpo{
private:
    string machine_choice;
    string options_list[3] = {"PEDRA", "PAPEL", "TESOURA"};
    int person_choice, quantity_chosen;
    bool control_variable;

public:

    Jokenpo(){
        creats_double_line();
        cout << "JOKENPÔ - CONTRA O COMPUTADOR" << endl;
        creats_double_line();
        machine_choice = "";
        person_choice = 0;
        control_variable = true;
    }


    void delay_time(){
        cout << "COMPUTADOR PENSANDO..." << endl;
        int list_points_quantity[9] = {2, 3, 4, 5, 6, 7, 8, 9, 10};

        int size = sizeof(list_points_quantity) / sizeof(list_points_quantity[0]); // Calcula o tamanho da lista

        // Inicializa o gerador de números aleatórios com o tempo atual
        srand(time(0));

        // Escolha aleatória de um índice dentro do intervalo válido
        int random_index = rand() % size;

        // Item escolhido aleatoriamente
        quantity_chosen = list_points_quantity[random_index];

        for (int i = 0; i < quantity_chosen; i++){
            float seconds_list[5] = {0.1, 0.2, 0.3, 0.4, 0.5};
            int seconds_size = sizeof(seconds_list) / sizeof(seconds_list[0]);
            int second_random_index = rand() % seconds_size;
            float seconds_chosen = list_points_quantity[second_random_index];
            this_thread::sleep_for(chrono::milliseconds(static_cast<int>(seconds_chosen * 100))); // Converte segundos para milissegundos
            cout << ".\n" << flush;
        }
        creats_double_line();
    }

    void creats_double_line(){
        cout << "========================================" << endl;
    }

    void creates_simple_line(){
        cout << "----------------------------------------" << endl;
    }

    void introduction(){;
        cout << "INSTRUCÕES DE COMO JOGAR:" << endl;
        creates_simple_line();
        cout << "1--PEDRA" << endl;
        cout << "2--PAPEL" << endl;
        cout << "3--TESOURA" << endl;
        cout << "0--SAIR" << endl;
        creates_simple_line();
    }

    string computer_choice_value(){
        int size = sizeof(options_list) / sizeof(options_list[0]); // Calcula o tamanho da lista

        // Inicializa o gerador de números aleatórios com o tempo atual
        srand(time(0));

        // Escolha aleatória de um índice dentro do intervalo válido
        int random_index = rand() % size;

        // Item escolhido aleatoriamente
        string choice = options_list[random_index];

        return choice;
    }

    int person_choice_value(){
        cout << "DIGITE O NÚMERO DA SUA ESCOLHA: ";
        cin >> person_choice;
        cin.ignore();
        creates_simple_line();
        return person_choice;
    }

    void show_choices(){
   
        while (control_variable){
            person_choice = person_choice_value();
            
            if (person_choice == 0){
                cout << "FIM DE JOGO!!!" << endl;
                control_variable = false;
            }

            else if (person_choice > 0 && person_choice < 4){
                delay_time();
                machine_choice = computer_choice_value();
                cout << "HUMANO(VOCÊ): " << options_list[person_choice - 1] << endl;
                cout << "COMPUTADOR:" << machine_choice << endl;
                creates_simple_line();
                checks_winner();
                control_variable = false;
            }

            else{
                cout << "VALOR INVÁLIDO!!! TENTE NOVAMENTE!!" << endl;
                creats_double_line();
            }
        }
    }

    void checks_winner(){
        if (options_list[person_choice - 1] == machine_choice){
            cout << "EMPATE!!!" << endl;
        }

        else{
                
            if (options_list[person_choice - 1] == "PEDRA" && machine_choice == "TESOURA" || options_list[person_choice - 1] == "PAPEL" && machine_choice == "PEDRA" || options_list[person_choice - 1] == "TESOURA" && machine_choice == "PAPEL"){

                cout << "VOCÊ VENCEU!!!" << endl;
            }

            else if (person_choice == 0){
                cout << "" << endl;
            }    
                
            else{
                cout << "VOCÊ PERDEU" << endl;
            }
        }
        if (person_choice != 0){
            creats_double_line();
            show_choices();
        }
    }        
};

int main(){
    Jokenpo start_game;
    start_game.introduction();
    start_game.show_choices();
    return 0;
}
