#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define e 2.71828
int errorexp = 0;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct stack {
    int top;
    unsigned max;
    int *data;
} Stack;

typedef struct stack2{
    int top;
    unsigned max;
    double *data;
} Stack2;
int isEmpty(Stack *stack) {
    if (stack->top == -1) {
        return 1;
    }
    return 0;
}
int isFull(Stack *stack) {
    return stack->top >= stack->max -1;
}

void push(Stack *stack, char data) {
    stack->data[++stack->top] = (int)data;
    if (!isFull(stack)) {
        stack->data[stack->top + 1] = '\0';
    }
}

char pop(Stack *stack) {
    if (!isEmpty(stack)) {
        return (char)stack->data[stack->top--];
    }
    return '.';
}

char peek(Stack *stack) {
    return (char)stack->data[stack->top];
}

int isOperand(char a) {
    return (a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9' || a == '.');
}

int precedence(char a) {

    switch (a) {
        case '+':
        case '-':
        
            return 1;

        case '*':
        case '/':
        case '%':
            return 2;

       
        
        
         case '^':  
        
            return 3;
            return -1;
    }

}

int isDigit(char c) {
    return (c >= '0' && c <= '9');
}
void build_row(Stack *stack, char *result, char *data, int i){
    
}
int isEmpty2(Stack2 *stack) {
    if (stack->top == -1) {
        return 1;
    }
    return 0;
}

void push2(Stack2 *stack, double data) {
    stack->data[++stack->top] = data;
}

int factorial(int n) {
    int fac=1;
    for(int i=n; i>=1; i--) {
        fac = fac*i;
    }
    return fac;
}


double pop2(Stack2 *stack) {
    if (!isEmpty2(stack)) {
        return stack->data[stack->top--];
    }
}
double calculate(double op1, double op2, char OPERATOR) {
    switch (OPERATOR) {
        case '+':
            return op2 + op1;
        case '-':
            return op2 - op1;
        case '*':
            return op2 * op1;
        case '/':
            return op2 / op1;
        case '^':
            return pow(op2, op1);
        case '%':
            return (op1/100);
        
        default:
        return -1;
    }
}
double evaluate(char data[]) {
    Stack2 *stack = (Stack2 *)malloc(sizeof(Stack2));
    stack->top = -1;
    stack->max = strlen(data);
    stack->data = (double *)malloc(sizeof(double) * stack->max);

    double op1, op2, temp, temp2;
    int perc, neg = 0;
    for (int i = 0; i < stack->max; i++) {
        if (data[i] == ' '){
            continue;
        }
        if (isDigit(data[i])) {

            temp = 0;
            temp2 = 0;
            while (isDigit(data[i])) {
                temp = temp * 10 + (int)(data[i++] - '0');
            }
            if (data[i] == '.') {
                i++;
                perc = 10;
                while(isDigit(data[i])) {
                    temp2 += ((double)((int)(data[i++] - '0'))/(perc));
                    perc *= 10;
                }
            } else {
                i--;
            }
            if(neg){
                push2(stack, -(temp + temp2));
                neg = 0;
            } else {
                push2(stack, temp + temp2);
            }
        } else {
            if (data[i] == '-' && (data[i+1] != ' ' && data[i+1] != '\0')){
                neg = 1;
                continue;
            }
            op1 = pop2(stack);
            op2 = pop2(stack);
            push2(stack, calculate(op1, op2, data[i]));
           
        }
    }
    return pop2(stack);
}
int isNegative(char *data, int i){
    for (int j = i - 1; i >= 0; i--) {
        if (data[j] != ' ') {
            if (isOperand(data[j])) {
                return 0;
            }
            return 1;
        }
    }
    return 1;
}
char *convert(char *data) {

    Stack *stack = (Stack *) malloc(sizeof(Stack));
    stack->max = strlen(data);
    stack->data = (int *) malloc(stack->max * sizeof(int));
    stack->top = -1;
    int i = 0, j = 0;
    char *result = (char *)malloc(stack->max * 2);
    result[0] = '\0';
    
    for (; data[i]; i++) {
        if (data[i] == ' ') {
            continue;
        }
        result[j+1] = '\0';
        build_row(stack, result, data, i);
        if (isOperand(data[i])) {
            result[j++] = data[i];
        } else {
            switch (data[i]) {
                case '(':
                    push(stack, data[i]);
                    break;
                case ')':
                    while (!isEmpty(stack) && peek(stack) != '(') {
                        result[j++] = ' ';
                        result[j++] = pop(stack);
                        build_row(stack, result, data, i);
                    }
                    pop(stack);
                    break;
                default:
                    if ((data[i] == '-' && data[i-1] == '(') || (data[i] == '-' && isNegative(data, i)) || (data[i] == '-' && i == 0)) {
                        result[j++] = data[i];
                    }else{

                        result[j++] = ' ';
                        while (!isEmpty(stack) && precedence(data[i]) <= precedence(peek(stack))) {
                            result[j++] = pop(stack);
                            result[j++] = ' ';
                            build_row(stack, result, data, i);
                        }
                        push(stack, data[i]);
                    }
            }
        }

    }
    build_row(stack, result, data, i);
    while (!isEmpty(stack)) {
        result[j++] = ' ';
        result[j++] = pop(stack);
        result[j] = '\0';
        build_row(stack, result, data, i);
    }
    return result;
}

void reset(char display_store[], char input_buffer[])
{
    for (int res = 0; res < (strlen(display_store)); res++)
    {
        display_store[res] = 0;
    }
    for (int res = 0; res < (strlen(input_buffer)); res++)
    {
        input_buffer[res] = 0;
    }
}



void solveEquations(double a1, double b1, double c1, double a2, double b2, double c2, char arr[]) {
    double determinant, x, y;
    determinant = a1 * b2 - a2 * b1;
    if (determinant != 0) {
        x = (c1 * b2 - c2 * b1) / determinant;
        y = (a1 * c2 - a2 * c1) / determinant;
       
        sprintf(arr, "x= %lf     y=%lf", x,y);
    }

    
else if((a1/a2) == (b1/b2) ) {
sprintf(arr, "Oops! No solution");
}
else   {
sprintf(arr, "Oops! Infinite solution");
}
}


void solvequad (double a, double b, double c, char arr[]) {
    double discriminant, x, y;
      discriminant = b * b - 4 * a * c;
   if (discriminant >= 0) {
        
        x = (-b + sqrt(discriminant)) / (2 * a);
        y = (-b - sqrt(discriminant)) / (2 * a);
        
        sprintf(arr, "x1= %lf     x2=%lf", x,y);
    }
    else {
sprintf(arr, "Oops! Complex roots!");
}
}
    void reset_equ (char arr[]) {
    for (int ijk = 0; ijk < strlen(arr); ijk++)
				{
					arr[ijk] = 0;
				}
}


int GCD(int a, int b)
{ 
    int GCD = 1;
    for (int q = 1; q <= a && q <= b; q++) 
    {
        if (a % q == 0 && b % q == 0) 
        {
            GCD = q;
        }
    }
    return GCD;
}
 
void fraction(int *num, int *den)
{
    for (int q = 2; q <= *num && q <= *den; q++) 
    {
        if (*num % q == 0 && *den % q == 0) 
        {
            *num = *num / q;
            *den = *den / q;
        }
    }
    
}
 
int convertStoD(double answer, char stod[]) 
{
    int c = 10000;
    double b = (answer - floor(answer)) * c;
    int numerator = (int)floor(answer) * c + (int)(b + .5f);
 
    while (1) 
    {
        if (numerator % 10 == 0) 
        {
            numerator = numerator / 10;
            c = c / 10;
        }
        else
            break;
    }

    int* numer = &numerator;
    int* denom = &c;
    int t = 0;
    while (t != 1)
    {
        int gcf = GCD(numerator, c);
        if (gcf == 1) 
        {sprintf(stod, "%d/%d", numerator, c);
            t = 1;
        }
        else
        {
            fraction(numer, denom);
        }
    }
}

int errorcheck (char arr[]) {
    for(int k=0; k<strlen(arr); k++) {
        if(   !isdigit (arr[k]) && arr[k] != '.'&&arr[k] != '-') return 0;
    }
}



