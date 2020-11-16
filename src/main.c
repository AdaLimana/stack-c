/* 
 * File:   main.c
 * Author: adair
 *
 * Created on 15 de Novembro de 2020, 19:18
 */

#ifdef _WIN32
#include <conio.h>
#else
#define clrscr() printf("\e[1;1H\e[2J")
#endif

#include "stack.h"

void menu(stack *s);

int main(int argc, char** argv) {

    stack s;
    
    initializeStack(&s);
    
    menu(&s);
    
    clear(&s);
        
    return 0;
}

void menu(stack *s){
    
    clrscr();
    printf("#############################################\n");
    printf("#                                           #\n");
    printf("# (1) TO ADD ITEM TO THE STACK, TYPE 1      #\n");
    printf("# (2) TO REMOVE ITEM FROM THE STACK, TYPE 2 #\n");
    printf("# (3) TO PRINT STACK ITEMS, TYPE 3          #\n");
    printf("# (4) TO EMPTY THE STACK, TYPE 4            #\n");
    printf("# (5) TO CLOSE APP, TYPE 5                  #\n");
    printf("#                                           #\n");
    printf("#############################################\n");
    
    int command = 0;
    
    scanf("%d", &command);
    
    if(command == 1){
        
        int value = 0;
        printf("TYPE A INTEGER NUMBER TO ADD TO THE STACK\n");
        scanf("%d", &value);
        push(s, value);        
    }
    else if(command == 2){
        pop(s);
    }
    else if(command == 3){
        printStack(s);
        printf("PRESS [ENTER] KEY TO CONTINUE");
        while(getchar()!='\n');
        getchar();
    }
    else if(command == 4){
        clear(s);
    }
    else if(command == 5){
        return;
    }
    else{
        printf("Command not found \n");
    }
    menu(s);
}