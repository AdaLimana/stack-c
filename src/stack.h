/* 
 * File:   stack.h
 * Author: adair
 *
 * Created on 15 de Novembro de 2020, 19:21
 */

#ifndef STACK_H
#define STACK_H

#ifdef __cplusplus
extern "C" {
#endif
    #include <stdlib.h>
    #include <stdio.h>

    typedef struct {

        int value;
        void *next;
    
    } item;

    typedef struct {

        int length;
        item *first;
        item *last;
    
    } stack;

    void initializeStack(stack *s);
    
    void push(stack *s, int value);
    
    int pop(stack *s);
    
    void clear(stack *s);
    
    void printStack(stack *s);

#ifdef __cplusplus
}
#endif

#endif /* STACK_H */

