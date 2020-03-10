#include <iostream>
using namespace std;


//constexpr size_t c_row = 3;
//constexpr size_t c_col = 4;
const size_t c_row = 3; //ok too
const size_t c_col = 4;



//using multiArray = int (&)[c_row][c_col]; //ok
typedef const int (&multiArray)[c_row][c_col]; //ok

void loopByReference(int (&array)[c_row][c_col]) {
    cout << __func__ << endl;
    for (const int (&row)[c_col] : array) {  //nust &row than row, otherwise array decay to int (*)[c_col] who do not have begin(), then next line code will go wrong.
        for (const int &col: row) {
            cout << col << "\t";
        }
        cout << endl;
    }
}

void loopByReference2(multiArray array) {
    cout << __func__ << endl;
    for (const int (&row)[c_col] : array) {
        for (const int col: row) {
            cout << col << "\t";
        }
        /*
        //work too
        for (const int &col: row) {
            cout << col << "\t";
        }
        */
        cout << endl;
    }
}


void loopByReferenceAndAuto(multiArray array) {
    cout << __func__ << endl;
    for (auto & row : array) {
        for (auto col: row) {
            cout << col << "\t";
        }
        cout << endl;
    }
}



using p_multiArray = const int (*)[c_row][c_col]; //pointer to 2D-array.
//using p_multiArray = const int (**)[c_row][c_col];//wrong! I thought it is OK but it isn't.
using p_array = const int (*)[c_col];

void loopByPointer(p_multiArray pma) { //also, ia will convert to its first element which type is int (*)[4] rather than itself type which is int (**)[3][4]. So use &ia, but this is ugly. 
    cout << __func__ << endl;
    //for (auto row: pma) {  //wrong, since pointer do not have begin() function which is used by range-for.
    for (p_array row = *pma; row!=*pma+c_row; row++) {
        for (const int * col = *row; col!= *row+c_col; col++) {
            cout << *col << "\t";
        }
        cout << endl;
    }

    cout << __func__ << " use auto" << endl;
    {
        for (auto row = *pma; row!=*pma+c_row; row++) {
            for (auto col = *row; col!= *row+c_col; col++) {
                cout << *col << "\t";
            }
            cout << endl;
        }
    }

}

//typedef int (const *p_array)[4];
void loopByPointer2(p_array parr) { //ia convert to its first element which is "int (*)[4]" type
    cout << __func__ << endl;
    for (p_array row=parr; row!=parr+c_row; row++) {
        for (const int *col=*row; col!=*row+c_col; col++) { //row is "int (*)[4] than an array, so, it can not convert to const int *.
            cout << *col << "\t";
        }
        cout << endl;
    }
    
    cout << __func__ << " use auto" << endl;
    {
        for (auto row=parr; row!=parr+c_row; row++) {
            for (auto col=*row; col!=*row+c_col; col++) { //row is "int (*)[4] than an array, so, it can not convert to const int *.
                cout << *col << "\t";
            }
            cout << endl;
         }
    }
}  

int main(int argc, char** argv) {
    int ia[c_row][c_col] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };    
    loopByReference(ia);
    loopByReference2(ia);
    loopByReferenceAndAuto(ia);
    loopByPointer(&ia);
    loopByPointer2(ia);
}


