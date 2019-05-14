/*
- Must be written in C
- Must compile and run on Linux Slax
- Save text file in ASCII encoding
- Process table up to 10 spaces
- Only allow up to 7 processes however
- User must input process name (characters, numbers) (case-sensitive is optional), max lenght 20 chars.
- User must input how many CPU cycles said process must run for.
- PIDs are generated automatically by the program, starting from 100.
- Processes CAN have the same name since they have unique PIDs
- Do not re-use PIDs
- To edit processes, user must inform PID
- For each CPU cycle, program must (sleep) for 1 second.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAX_PROCESSES 7
#define QUEUE_SIZE 10

int pid_counter = 100;

struct Process{
    char name[20];
    int PID;
    int CPU;
};

void main_menu(){
    int running = 1;
    char option;

    while (running == 1){
        system("clear");
        puts("--------------------------------");
        puts("Gerenciador de fila de prontos");
        puts("--------------------------------");
        puts("1. Manipulação da tabela de processos");
        puts("2. Executar simulação");
        puts("3. Copyright");
        puts("4. Encerrar");
        puts("--------------------------------");
        puts("Opção:");
        
        scanf("%c", &option);
        
        if (option == '1'){
            table_menu();
        }
        else if (option == '2'){
            simulation();
        }
        else if (option == '3'){
            copyright();
        }
        else if (option == '4'){
            puts("Goodbye...");
            return 0;
        }
        else {
            // Some code is supposed to be here ))
            puts("main_menu(): Only numbers between 1~4 are valid input!");
            puts("Press [ENTER] to continue.");
            getchar();
        }
    }
}

void table_menu(){
    int running = 1;
    char option;
    
    system("clear");
    while (running == 1){

        puts("Manipulação da tabela de processos");
        puts("------------------------------");
        puts("1. Inserir processos (nome, ciclos de cpu)");
        puts("2. Alterar processos");
        puts("3. Remover processos");
        puts("4. Listar a tabela");
        puts("");
        puts("0. Retornar ao menu principal");
        puts("------------------------------");
        puts("Opção:");
        
        scanf("%c", &option);
        
        if (option == '1'){
            //add_process();
        }
        else if (option == '2'){
            //edit_process();
        }
        else if (option == '3'){
            //remove_process();
        }
        else if (option == '4'){
            //list_processes();
        }
        else if (option == '0'){
            running = 0;
            main_menu();
        }
        else {
            // Some code is supposed to be here ))
            puts("table_menu(): Only numbers between 1~4 are valid input!");
            puts("Press [ENTER] to continue.");
            getchar();
        }
        
    }
}

void simulation(){
}

void copyright(){
    puts("yoink github.com/parklez");
}

int main(){
    // TODO: Initiliaze arrays and stuff
    
    main_menu();
    return 0;
}