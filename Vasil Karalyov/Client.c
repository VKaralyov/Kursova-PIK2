#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strcmp
#include "Data.h"

#define NumOfTables 20
#define OptionSize 10

res_t Data[NumOfTables];
char option[OptionSize] = {'\0'};
unsigned int tableNum = 1;

void show(){
    for(tableNum = 1; tableNum <= NumOfTables; tableNum++){
        if(Data[tableNum-1].price != 0){
            printf("Table %d: %d/%d/%d\tName: %s\tPayed:%d\tTotal: %d\n", tableNum, Data[tableNum-1].day, Data[tableNum-1].month, Data[tableNum-1].year, Data[tableNum-1].name, Data[tableNum-1].payed, Data[tableNum-1].price);
        }else{
            printf("Table %d is free.\n", tableNum);
        }
    }
}

void reserve(FILE *logf){
    while(1){
        printf("\nClient\\reserve>");
        if( gets(option) != NULL){
            if( !strcmp(option, "exit") ){
                break;
            }else{
                if( !strcmp(option, "show") ){
                    show();
                }else{
                    if( !strcmp(option, "input") ){
                        printf("Reserve table: ");
                        if( scanf("%d", &tableNum) > 0 ){
                            printf("Name: ");
                            scanf("%s", &Data[tableNum-1].name);
                            printf("Date (format dd:mm:yyyy): ");
                            scanf("%d %d %d", &Data[tableNum-1].day, &Data[tableNum-1].month, &Data[tableNum-1].year);
                            printf("Total: ");
                            scanf("%d", &Data[tableNum-1].price);
                            printf("Payed: ");
                            scanf("%d", &Data[tableNum-1].payed);
                            fprintf(logf, "Reserved table %d: %d/%d/%d\t%s\tPayed:%d\tTotal:%d\n", tableNum, Data[tableNum-1].day, Data[tableNum-1].month, Data[tableNum-1].year, Data[tableNum-1].name, Data[tableNum-1].payed, Data[tableNum-1].price);
                        }else printf("Not a valid number!");
                    }else{
                        printf("Unrecognized command! Check your spelling.\n");
                    }
                }
            }
        }
    }
}

void editInfo(FILE *logf){
    while(1){
        printf("\nClient\\edit-info>");
        if( gets(option) != NULL){
            if( !strcmp(option, "exit") ){
                break;
            }else{
                if( !strcmp(option, "show") ){
                    show();
                }else{
                    if( !strcmp(option, "edit") ){
                        printf("Edit table: ");
                        if( scanf("%d", &tableNum) > 0 ){
                            printf("What attribute do you want to edit: ");
                            if( gets(option) != NULL){
                                if( !strcmp(option, "name") ){
                                    scanf("%s", &Data[tableNum-1].name);
                                }
                                if( !strcmp(option, "date") ){
                                    scanf("%d %d %d", &Data[tableNum-1].day, &Data[tableNum-1].month, &Data[tableNum-1].year);
                                }
                                if( !strcmp(option, "total") ){
                                    scanf("%s", &Data[tableNum-1].price);
                                }
                                if( !strcmp(option, "payed") ){
                                    scanf("%s", &Data[tableNum-1].payed);
                                }
                            }
                            fprintf(logf, "Edited (%s) table %d: %d/%d/%d\t%s\tPayed:%d\tTotal:%d\n", option, tableNum, Data[tableNum-1].day, Data[tableNum-1].month, Data[tableNum-1].year, Data[tableNum-1].name, Data[tableNum-1].payed, Data[tableNum-1].price);
                        }else printf("Not a valid number!");
                    }else{
                        printf("Unrecognized command! Check your spelling.\n");
                    }
                }
            }
        }
    }
}

void freeup(FILE *logf, FILE *repf){
    printf("Free table: ");
    if( scanf("%d", &tableNum) > 0 ){
        if( tableNum > 0 && tableNum <= 20){
            fprintf(repf, "%d/%d/%d\tTable %d\tPayed: $%d", Data[tableNum-1].day, Data[tableNum-1].month, Data[tableNum-1].year, tableNum, Data[tableNum-1].payed);
            Data[tableNum-1].day = 0;
            Data[tableNum-1].month = 0;
            Data[tableNum-1].year = 0;
            Data[tableNum-1].price = 0;
            Data[tableNum-1].payed = 0;
            printf("Table %d is now free", tableNum);
            fprintf(logf, "Table %d is now free", tableNum);
        }else printf("Error: Invalid table number!");
    }else printf("Not a valid number!");
}

void help(){
    printf("\nThank you for using my app.\n");
    printf("Here is some info on what the app can do:\n\n");
    printf("help  -  shows all commands.\n");
    printf("reserve  -  Reserve a table.\n");
    printf("editinfo  -  Edit reserved table info.\n");
    printf("freeup  -  Delete reserved tables.\n");
    printf("show  -  Shows currently saved info.\n");
}

int main(){
    printf("--------------------- \n");
    printf("--------------------- \n");
    printf("-------Welcome!------ \n");
    printf("--------------------- \n");
    printf("--------------------- \n");

    FILE *log,*report;
    log = fopen("log.txt", "w");
    report = fopen("report.txt", "w");

    while(1){
        printf("\nClient>");
        if( gets(option) != NULL){
            if( !strcmp(option, "exit") ){
                break;
            }else
                if( !strcmp(option, "help") ){
                    help();
                }else
                    if( !strcmp(option, "reserve") ){
                        reserve(log);
                    }else
                        if( !strcmp(option, "editinfo") ){
                            editInfo(log);
                        }else
                            if( !strcmp(option, "freeup") ){
                                freeup(log, report);
                            }else
                                if( !strcmp(option, "show") ){
                                    show();
                                }else{
                                    printf("Unrecognized command! Check your spelling.\n");
                                }
        }
    }

    fclose(report);
    fclose(log);
    printf("\nGoodbye...");
    return 0;
}
