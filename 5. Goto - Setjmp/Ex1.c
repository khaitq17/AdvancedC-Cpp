#include<stdio.h>
#include<setjmp.h>

jmp_buf buf;
int exception_code;
char *error_code;

#define TRY             if((exception_code = setjmp(buf)) == 0)
#define CATCH(x)        else if(exception_code == x)
#define THROW(x, ERROR) {error_code = ERROR; longjmp(buf, x);}

double divide(int a, int b){
   if(b == 0){
        THROW(1, "Error: Divided by 0!"); 
   }
   if(b == 5){
        THROW(2, "Error: Other errors!");
   }
    
   return (double)a / b;
}

int main(){
    int a = 17, b = 3;
    double result;

    TRY{
        result = divide(a, b);
        printf("Result: %.2f\n", result);
    } CATCH(1){
        printf("%s\n", error_code);
    } CATCH(2){
        printf("%s\n", error_code);
    }

    return 0;
}







