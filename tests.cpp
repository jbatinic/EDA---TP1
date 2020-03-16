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




int main (void) {

    arg_struct userData[10];
    
    int result;
    
    //TEST 1:

    char* test1[] = {"my_exe","-maxclients","2","hello"};

    if ((result = parseCmdLine(3, test1, parseCallback, &userData)) != -1) {
        cout << "Test 1 successful!" << endl << "Total arguments: " << result << endl;
        //  cout << (userData[0]).clave << endl << (userData[0]).parametro << endl;
    }
    else {
        cout << "Test 1 unsuccessful!" << endl;
    }
    
    return 0;
}
