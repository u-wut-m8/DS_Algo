#include <iostream>
#include <set>

bool notInRow(int **mat, const int& row) {
    std::set<int> st;
    for(int i=0;i<9;i++){
        if(st.find(mat[row][i]) != st.end())
            return false;
        if(mat[row][i] != 0)
            st.insert(mat[row][i]);
    }
    return true;
}

bool notInCol(int **mat, const int& col) {
    std::set<int> st;
    for(int i=0;i<9;i++){
        if(st.find(mat[i][col]) != st.end())
            return false;
        if(mat[i][col] != 0)
            st.insert(mat[i][col]);
    }
    return true;
}

bool notInBox(int **mat, const int& startRow, const int& startCol) {
    std::set<int> st;
    for(int row=0;row<3;row++)
        for(int col=0;col<3;col++) {
            int curr = mat[row+startRow][col+startCol];
            if(st.find(curr) != st.end())
                return false;
            if(curr != 0)
                st.insert(curr);
        }
    return true;
}

bool isValid(int **mat, const int& row, const int& col) {
    return notInRow(mat, row) && notInCol(mat, col) && notInBox(mat, row-row%3, col-col%3);
}

bool isValidConfig(int **mat) {
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            if(!isValid(mat, i, j))
                return false;
    return true;
}

int main(int argc, char *argv[]) {
    int T, **mat;
    std::cin>>T;
    while(T--) {
        mat = new int*[9];
        for(int i=0;i<9;i++)
            mat[i] = new int[9];
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                std::cin>>*(*(mat+i)+j);
        std::cout<<isValidConfig(mat)<<std::endl;
        for(int i=0;i<9;i++)
            delete[] mat[i];
        delete[] mat;
    }
    return 0;
}