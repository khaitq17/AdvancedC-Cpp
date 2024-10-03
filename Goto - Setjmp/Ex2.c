#include<stdio.h>
#include<setjmp.h>

jmp_buf buf;
int exception_code;
char *error_message;

#define TRY                if((exception_code = setjmp(buf)) == 0)
#define CATCH(x)           else if(exception_code == x)
#define THROW(x, ERROR)    {error_message = #ERROR; longjmp(buf, x);}

enum ErrorCodes{
    NO_ERROR,
    FILE_ERROR,
    NETWORK_ERROR,
    CALCULATION_ERROR
};


void readFile(){
    printf("Read file ...\n");
    THROW(FILE_ERROR, "Error: File not exist!");
}

void networkOperation(){
    printf("Network operation ...\n");
    THROW(NETWORK_ERROR, "Error: Unable to access the network!");
}

void calculateData(){
    printf("Calculate data ...");
    THROW(CALCULATION_ERROR, "Error: Can not calculate!");
}

int main(){
    TRY{
        readFile();
        networkOperation();
        calculateData();
    } CATCH(FILE_ERROR){
        printf("%s\n", error_message);
    } CATCH(NETWORK_ERROR){
        printf("%s\n", error_message);
    } CATCH(CALCULATION_ERROR){
        printf("%s\n", error_message);
    }

    return 0;
}














