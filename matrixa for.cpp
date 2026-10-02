#include <iostream>
int main(){
    int stlb, strok;
    if (!(std::cin>>stlb>>strok)){
        return 1;
    }
    int **matrix = new (std::nothrow) int*[strok];
    if (matrix == nullptr){
        return 2;
    }
    for (int i = 0; i < strok;++i){
        matrix[i] = new(std::nothrow) int[stlb];
        if (matrix[i] == nullptr){
            for (int j = 0; j < i; ++j){
                delete[] matrix[j];
            }
            delete[] matrix;
            return 2;
        }
        for (int j = 0; j < stlb; ++j) {
            if (!(std::cin >> matrix[i][j])) {
                for (int k = 0; k <= i; ++k) {
                    delete[] matrix[k];
                }
                delete[] matrix;
                return 1;
            }
        }
    }
    for (int j = 0; j < stlb; ++j) {
        for (int i = 0; i < strok; ++i) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
        }
    for (int i = 0; i < strok; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}