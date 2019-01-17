#include <iostream>

int main(int argc, char *argv[])
{
    for(int row=5;row>=1;row--){
        for(int column=row;column>=1;column--)
            std::cout<<'#';
        std::cout<<std::endl;
    }
    return 0;
}
