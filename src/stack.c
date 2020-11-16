
#include "stack.h";

void initializeStack(stack *s){

    s->length = 0;
    s->first = 0;
    s->last = 0;
}

void push(stack *s, int value){

    item *i = (item*) malloc(sizeof(item));
    i->value = value;

    if(s->length == 0){

        s->first = i;
        s->last = i;
        s->length++;
    }
    else{

        item *first = s->first;
        i->next = first;
        s->first = i;
        s->length++;
    }
}

int pop(stack *s){
    
    if(s->length == 0){
        printf("Empty Stack\n");
        return 0;
    }
    
    item* first = s->first;
    s->first = first->next;
    s->length--;
    
    int value = first->value;
    
    free(first);
    
    return value;   
}

void clear(stack *s){
    
    item *i = s->first;
    
    while(i){
        
        s->first = i->next;
        s->length--;
        free(i);
        i = s->first;
    }
}

void printStack(stack *s){

    item *i = s->first;
    
    if(s->length == 0){
        printf("Empty Stack\n");
    }
    
    printf("########\n");
        
    while(i){ 
        printf("# %4d #\n", i->value);
        printf("########\n");
        i = i->next;
    }
}