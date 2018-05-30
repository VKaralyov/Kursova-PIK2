#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Data.h"
#define OptionSize 10

void help(){
    printf("\nThank you for using my app.\n\n");
    printf("Here is some info on what the app can do:\n");
    printf("help  -  shows all commands.\n");
    printf("exit  -  Exit the program.\n");
    printf("start  -  Starts the client.\n");
}

int main(){

    char option[OptionSize];
    printf("--------------------- \n");
    printf("--------------------- \n");
    printf("------Welcome!------- \n");
    printf("----To the Server---- \n");
    printf("--------------------- \n");

    while(1){
        printf("\nServer>");
        if( gets(option) != NULL){

            if( !strcmp(option, "exit") ){
                break;
            }
            if( !strcmp(option, "help") ){
                help();
            }
            if( !strcmp(option, "start") ){
                system("Client.exe");
            }
        }
        //system("Pause");
        //system("CLS");
    }
    printf("Shutting down server...");
    return 0;
}
