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

typedef struct Process{
    char name[20];
    int PID;
    int CPU;
}Process;

// Globals
int pid_counter = 100;
int process_counter = 0;
Process process_array[MAX_PROCESSES];
int queue[QUEUE_SIZE];

// Functions
void simulation(){
    //TODO: Sort queue by process_array[i].PID
    //TODO: Code the actual simulation
    //TODO: Save results into a file 
}

// https://stackoverflow.com/questions/17318886/fflush-is-not-working-in-linux
void clean_stdin(void){
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

void add_process(){

    // Check if the user is allowed to create a process
    if (process_counter >= MAX_PROCESSES){
            printf("add_process(): Process queue is full [Max: %i]. Remove a process to add a new one!\n", MAX_PROCESSES);
            puts("Press [ENTER] to continue.");
            getchar();
            return;
    }

    // Finding free space to save the index of our process into the queue
    int i = 0;
    for (;i < QUEUE_SIZE;i++){
        if (queue[i] == -1){
            break;
        }
    }

    // Adding a new process to the array
    system("clear");
    puts("Digite o nome do processo:");
    scanf("%s", process_array[i].name);
    clean_stdin();

    puts("Digite a quantidade de ciclos a rodar:");
    scanf("%i", &process_array[i].CPU);

    process_array[i].PID = pid_counter;
    queue[i] = i;
    
    pid_counter++;
    process_counter++;

}

void list_processes(){
    int i = 0;

    system("clear");
    puts("Lista de processos");
    puts("------------------------");
    puts("PID - CPU Cycles - Nome");
    puts("------------------------");
    for (;i < QUEUE_SIZE; i++){
        if (queue[i] != -1){
            printf("%i - %i          - %s\n", process_array[queue[i]].PID, process_array[queue[i]].CPU, process_array[queue[i]].name);
        }
    }
    puts("------------------------");
    printf("Total: %i\n\n", process_counter);
    puts("Aperte [ENTER] para voltar ao menu de manipulação.");
    getchar();
}

void edit_process(){
    int PID;

    // xd
    if (process_counter == 0){
        puts("edit_process(): Lista de processos vazia, adicione um processo para editá-lo!");
        puts("Aperte [ENTER] para voltar ao menu de manipulação.");
        getchar();
        return;
    }
        
    system("clear");
    puts("Digite o PID do processo a ser editado:");
    scanf("%i", &PID);
    clean_stdin();

    // Check if that process ID exists
    int i = 0;
    int exists = 0;
    for (; i < process_counter; i++){
        if (process_array[i].PID == PID){
            exists = 1;
            break;
        }
    }

    // If that process exists, time to edit it
    if (exists == 1){
        puts("Digite um novo nome:");
        scanf("%s", &process_array[i].name);
        clean_stdin();
        puts("Digite uma nova quantidade de ciclos de CPU:");
        scanf("%i", &process_array[i].CPU);
    }
    else{
        puts("PID não encontrado!");
        puts("Aperte [ENTER] para voltar ao menu de manipulação.");
        getchar();
    }
}

void remove_process(){

    int PID;

    if (process_counter == 0){
        puts("remove_process(): Lista de processos vazia, adicione um processo para removê-lo!");
        puts("Aperte [ENTER] para voltar ao menu de manipulação.");
        getchar();
        return;
    }

    system("clear");
    puts("Digite o PID do processo para remoção:");
    scanf("%i", &PID);
    clean_stdin();

    int exists = 0;
    int i = 0;
    for (; i < QUEUE_SIZE; i++){
        if (process_array[queue[i]].PID == PID){
            exists = 1;
            break;
        }
    }

    if (exists == 1){
        queue[i] = -1;
        process_counter -= 1;

        printf("Processo de PID '%i' removido com sucesso!\n", PID);
        puts("Aperte [ENTER] para voltar ao menu de manipulação.");
        getchar();
        return;
    }

    else{
        printf("Processo de PID '%i' não encontrado!\n", PID);
        puts("Aperte [ENTER] para voltar ao menu de manipulação.");
        getchar();
        return;
    }
}

void table_menu(){
    int running = 1;
    char option;
    
    while (running == 1){
        system("clear");
        puts("Manipulação da tabela de processos");
        puts("------------------------------");
        puts("1. Inserir processo (nome, ciclos de cpu)");
        puts("2. Alterar processos");
        puts("3. Remover processos");
        puts("4. Listar a tabela");
        puts("");
        puts("0. Retornar ao menu principal");
        puts("------------------------------");
        puts("Opção:");
        
        scanf(" %c", &option);
        clean_stdin();

        if (option == '1'){
            add_process();
        }
        else if (option == '2'){
            edit_process();
        }
        else if (option == '3'){
            remove_process();
        }
        else if (option == '4'){
            list_processes();
        }
        else if (option == '0'){
            running = 0;
        }
        else {
            // Some code is supposed to be here ))
            puts("table_menu(): Only numbers between 1~4 are valid input!");
            puts("Press [ENTER] to continue.");
            getchar();
        }
    }
}

void copyright(){
    system("clear");
    puts("yoink github.com/parklez");
    puts("Press [ENTER] to return.");
    getchar();
}

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
        
        scanf(" %c", &option);
        clean_stdin();
        
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
            return;
        }
        else {
            // Some code is supposed to be here ))
            puts("main_menu(): Only numbers between 1~4 are valid input!");
            puts("Press [ENTER] to continue.");
            getchar();
        }
    }
}

int main(){
    // Define the entire queue as empty with -1
    int i = 0;
    for (; i < QUEUE_SIZE; i++){
        queue[i] = -1;
    }

    main_menu();

    return 0;
}
