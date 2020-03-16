#include "lib.h"
#include "string.h"
#include <stdio.h>
#include <string>
using namespace std;


int parseCallback(char* key, char* value, void* userData) {

    int sucess = 1;
    arg_struct * argumentos = (arg_struct *) userData;


    if (key) {

       if (!strcmp(key, "maxclients")) {
            argumentos->clave = value;
        }
        else {
            printf("Argument Error!\n");
            sucess = 0;
        }
    }
    else {
        if (value) {
            argumentos->parametro = value;
        }
        else {
            printf("Parameter Error!\n");
            sucess = 0;
        }
    }

    return sucess;

}

typedef struct {
    string  clave;
    string  parametro;
} arg_struct;



int main (int argc, char *argv[]) {

    arg_struct userData;

    int result = parseCmdLine(argc, argv, parseCallback, &userData);

    printf("Result = %d\n", result);
    if (result == -1 )
    {
        printf("Parsing Error!\n");
    }
    return 0;
}
