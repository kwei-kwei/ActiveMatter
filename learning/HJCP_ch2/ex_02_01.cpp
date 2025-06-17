#include <iostream>
#include <cmath>

using std::cout, std::cin, std::endl;

int* convert_float_to_binary(float);

int main(int argc, char* argv[]){

    int i;
    float number;
    int* bin;

    //number = 123.45;
    number = -0.4765625;

    bin = convert_float_to_binary(number);

    cout << "(";
    for (i=0; i<32; i++){
        cout << bin[i];
        if (i==8) {cout << " ";}
    }
    cout << ")_2" << endl;

    delete[] bin;
    return 0;
}

int* convert_float_to_binary(float num){
    int i;
    int* bin = new int[32];
    int exponent;
    float mantissa;

    for (i=0; i<32; i++){bin[i] = 0;}
    
    // setting the sign bit
    if (num < 0){
        bin[0] = 1;
        num *= -1;
    }

    // get exponent and mantissa
    exponent = (int) floor(log2(num));
    mantissa = num / pow(2., exponent);
    

    // add offset to exponent
    exponent += 127;

    // get binary representation of exponent
    for (i=7; i>=0; i--){
        bin[i+1] = exponent % 2;
        exponent /= 2;
    }

    mantissa *= 2;
    // get binary represnetation of mantissa
    for (i=0; i<23; i++){
        bin[i+9] = (int) floor(mantissa) % 2;
        mantissa *= 2;
    }

    return bin;
}
