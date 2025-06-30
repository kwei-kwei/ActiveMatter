#include <iostream>
#include <sstream>

using std::cout, std::endl;

using num_t = double;

num_t sum_up(int N);

num_t sum_down(int N);

int main(int argc, char* argv[]){

    int N;
    num_t s_up;
    num_t s_down;

    if (argc == 1){
        N = 1;
    } else{
        N = (int) atof(argv[1]);
    }

    s_up = sum_up(N);
    s_down = sum_down(N);

    cout << "S_up = " << s_up << endl;
    cout << "S_down = " << s_down << endl;

    return 0;
}

num_t sum_up(int N){
    num_t sn = 0;
    for (long i = 1; i <= N; i++){
        sn += (num_t) 1/i;
    }

    return sn;
}

num_t sum_down(int N){
    num_t sn = 0;
    for (long i = N; i >= 1; i--){
        sn += (num_t) 1/i;
    }

    return sn;
}
