
#include <iostream> // to input and output
#include <cstdlib> // to srand and rand
#include <ctime>   // to time
#include <chrono>  // to std::chrono::seconds
#include <thread>  // to std::this_thread::sleep_for

// to facilitate the use of std
using namespace std; 

// Escope of the game
class Jokenpo{ 
// Variables Privates    
private: 
    string machine_choice;
    string options_list[3] = {"PEDRA", "PAPEL", "TESOURA"};
    int person_choice, quantity_chosen;
    bool control_variable;

public: 
    // Constructor Method
    Jokenpo(){ 
        creats_double_line();
        cout << "JOKENPÔ - CONTRA O COMPUTADOR" << endl;
        creats_double_line();
        machine_choice = "";
        person_choice = 0;
        control_variable = true;
    }

    // Method to delay time
    void delay_time(){ 
        cout << "COMPUTADOR PENSANDO..." << endl;
        int list_points_quantity[9] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
       
        // Calculates list size
        int size = sizeof(list_points_quantity) / sizeof(list_points_quantity[0]); 

        // Initializes the random number generator with the current time
        srand(time(0));

        // Randomly choosing an index from a valid range
        int random_index = rand() % size;

        // randomly chosen item
        quantity_chosen = list_points_quantity[random_index];

        // choice of a random time for the computer to respond
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
    // Creates double line on screen
    void creats_double_line(){
        cout << "========================================" << endl;
    }
    // Creates simple line on screen
    void creates_simple_line(){
        cout << "----------------------------------------" << endl;
    }
    // Shows initial information
    void introduction(){;
        cout << "INSTRUCÕES DE COMO JOGAR:" << endl;
        creates_simple_line();
        cout << "1--PEDRA" << endl;
        cout << "2--PAPEL" << endl;
        cout << "3--TESOURA" << endl;
        cout << "0--SAIR" << endl;
        creates_simple_line();
    }

    // Function to computer choice
    string computer_choice_value(){
        int size = sizeof(options_list) / sizeof(options_list[0]);
        srand(time(0));
        int random_index = rand() % size;
        string choice = options_list[random_index];
        return choice;
    }
    // Function to person choice
    int person_choice_value(){
        cout << "DIGITE O NÚMERO DA SUA ESCOLHA: ";
        cin >> person_choice;
        cin.ignore();
        creates_simple_line();
        return person_choice;
    }
    // Show both choices
    void show_choices(){
        // Will happen as long as the variable is True
        while (control_variable){
            person_choice = person_choice_value();
            // If the choice is equal to zero, the game is over
            if (person_choice == 0){
                cout << "FIM DE JOGO!!!" << endl;
                control_variable = false;
            }
            // Shows picks, call delay, simple line and winner
            else if (person_choice > 0 && person_choice < 4){
                delay_time();
                machine_choice = computer_choice_value();
                cout << "HUMANO(VOCÊ): " << options_list[person_choice - 1] << endl;
                cout << "COMPUTADOR:" << machine_choice << endl;
                creates_simple_line();
                checks_winner();
                control_variable = false;
            }
            // Error treatment 
            else{
                cout << "VALOR INVÁLIDO!!! TENTE NOVAMENTE!!" << endl;
                creats_double_line();
            }
        }
    }
    // Checks winner
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

// Main code
int main(){
    // Instance with functions calls 
    Jokenpo start_game;
    start_game.introduction();
    start_game.show_choices();
    return 0;
}
