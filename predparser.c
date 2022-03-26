#include<stdio.h>

void exp();
void term();
void reset_exp();
void reset_term();
void factor();
void match(char token);
char nexttoken();

char lookahead; //입력받은 내용을 char단위로 순서대로 쪼개 보여주는 역할을 하게됨.

char nexttoken() {
    char c;
    while (1) {
        c = getchar(); // 입력받기.
        if (c == ' ' || c == '\t' || c == '\n' || c == '\0') continue;
        
        return(c) ;
    }
}

void match(char token) {
   
    if (lookahead == token)
        lookahead = nexttoken(); //lookahead 가 입력받은 토큰과 같으면 다음 토큰을 받아옴.
    else {
        printf(" error\n");
        exit(1);
    }
}

void exp(){
    term(); printf("3"); reset_exp();
}
void reset_exp(){
    if(lookahead == '+'){
            match('+'); term(); printf("1"); reset_exp();
    }
    if(lookahead == '-'){
            match('-'); term(); printf("2"); reset_exp();
    }
}
void term(){
    factor(); printf("6"); reset_term();
}
void reset_term(){
    if(lookahead == '*'){
        match('*'); factor(); printf("4"); reset_term();
    }
    if(lookahead == '/'){
        match('/'); factor(); printf("5"); reset_term();
    }
}

void factor(){
    if(
        lookahead == '0'||lookahead == '1'|| 
        lookahead == '2'||lookahead == '3'||
        lookahead == '4'||lookahead == '5'||
        lookahead == '6'||lookahead == '7'||
        lookahead == '8'||lookahead == '9'
        ){
        match(lookahead);
    }
    else{
        match('('); exp(); match(')'); printf("7");
    }
    
}

void main() {
    
    lookahead = nexttoken();

    exp(); //번역계획의 expr을 의미 (exp를 통해 코드화된 번역계획을 계속해감.)
    if (lookahead == '$'){
        printf("\n");
    }
    else{
        printf(" error\n");
    }
}