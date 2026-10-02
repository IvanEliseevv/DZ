#include <iostream>
int main() {
    int stl, strok;
    std::cin>>stl>>strok;
    int arr[strok][stl];
    for(int i=0; i<strok; i++) {
        for(int j=0; j<stl; j++) {
            std::cin>>arr[i][j];
        }
    }
    for (int i=0; i<strok; i++){
        for (int j=0; j<stl; j++){
            std::cout<<arr[i][j]<<" ";
        }
        std::cout<<std::endl;
    }

}