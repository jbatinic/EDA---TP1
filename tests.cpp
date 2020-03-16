#include "lib.h"
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;


typedef struct {
    string  clave;
    string  parametro;
} arg_struct;

int parseCallback(char* key, char* value, void* userData) {

    int sucess = 1;
    arg_struct * argumentos = (arg_struct *) userData;
    string my_key(key);
    string my_value(value);


    if (key) {

       if (!strcmp(key, "maxclients")) {
            argumentos->clave = my_key;
        }
        else {
            printf("Argument Error!\n");
            sucess = 0;
        }
    }
    
    if (value) {
        argumentos->parametro = my_value;
    }
    else {
        printf("Parameter Error!\n");
        sucess = 0;
    }
    
    return sucess;

}




int main (int argc, char *argv[]) {

    arg_struct userData[10];

    int result = parseCmdLine(argc, argv, parseCallback, &userData);

        cout << (userData[0]).clave << endl << (userData[0]).parametro << endl;

    printf("Result = %d\n", result);
    if (result == -1 )
    {
        printf("Parsing Error!\n");
    }
    return 0;
}
