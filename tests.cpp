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

    int success = 1;
    arg_struct * argumentos = (arg_struct *) userData;
    string my_key(key);
    string my_value(value);


    if (key) {

       if ( true /*!strcmp(key, "maxclients")*/) {
            argumentos->clave = my_key;
        }
        else {
            printf("Argument Error!\n");
            success = 0;
        }
    }
    
    if (value) {
        argumentos->parametro = my_value;
    }
    else {
        printf("Parameter Error!\n");
        success = 0;
    }
    
    if (success) {
        userData = (arg_struct*)userData + 1;
    }

    return success;

}



int main (void) {

    int result;
    int i;

    //TEST 1:

    char* test1[] = {"my_exe","-maxclients","2","hello"};
    arg_struct test1_data[5];

    if ((result = parseCmdLine(4, test1, parseCallback, &test1_data)) != -1) {
        cout << "Test 1 successful!!" << endl << "Total arguments: " << result << endl;
        for (i = 0; i < 5; i++) {
            cout << (test1_data[i]).clave << endl << (test1_data[i]).parametro << endl;
        }
        
    }
    else {
        cout << "Test 1 unsuccessful!" << endl;
    }

    // TEST 2:

    char* test2[] = { "my_exe","-maxclients"};
    arg_struct test2_data[5];

    if ((result = parseCmdLine(2, test1, parseCallback, &test2_data)) == -1) {
        cout << "Test 1 successful!!" << endl << "Invalid syntax" << endl;
    }
    else {
        cout << "Test 1 unsuccessful!" << endl;
    }

    // TEST 3:

    char* test3[] = { "my_exe","-", "hello"};
    arg_struct test3_data[5];

    if ((result = parseCmdLine(3, test1, parseCallback, &test3_data)) == -1) {
        cout << "Test 1 successful!!" << endl << "Invalid syntax" << endl;
    }
    else {
        cout << "Test 1 unsuccessful!" << endl;
    }

    // TEST 4:

    char* test4[] = { "my_exe","-its_a_key", "its_a_value", "its_a_parameter", "another_parameter", "-another_key?", "yes_and_another_value!"};
    arg_struct test4_data[5];

    if ((result = parseCmdLine(7, test1, parseCallback, &test4_data)) != -1) {
        cout << "Test 1 successful!!" << endl << "Total arguments: " << result << endl;
        for (i = 0; i < 5; i++) {
            cout << (test4_data[i]).clave << endl << (test4_data[i]).parametro << endl;
        }
    }
    else {
        cout << "Test 1 unsuccessful!" << endl;
    }

    return 0;
}
