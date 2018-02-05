//
//  main.cpp
//  Project1
//
//  Created by Loi Huynh on 1/22/18.
//  Copyright © 2018 Loi Huynh. All rights reserved.
//

#include <iostream>
using namespace std;

class DataFrame {
protected:
    
    int** table; // table is a pointer to a pointer to int
    int noRows, noCols;
    char** colNames; // colNames is a pointer to a pointer to char
    char** rowNames; // rowNames is a pointer to a pointer to char
    
public:
    
    //Constructors
    DataFrame ();
    
    DataFrame (int rows, int cols);
    
    //Output Method
    void display();
    
    //Setters
    void setRowName(int row, const char* name);
    void setColName(int col, const char* name);
    int* operator[] (int i); // return row i
    
    //Getters
    char** getRowNames();
    char** getColNames();
    int getNumberRows();
    int getNumberCols();
    DataFrame* getColumns(int* columns, int cLen);
    DataFrame* getRows(int* rows, int rLen);
    DataFrame* getRowsCols(int* rows, int rLen, int* cols, int cLen);
    
    //Destructor
    ~DataFrame();
};

DataFrame::DataFrame() { // DONE
    // Default constructor
    // Simon (TA) said nothing needs to be done here.
}

DataFrame::DataFrame(int rows, int cols) { // DONE: CHECK IT
    /** Set up the dataframe table **/
    noRows = rows;
    noCols = cols;
    
    /** Set up the table itself **/
    
    table = new int*[noRows]; // double pointers allow us to initialize an array of rows size where each element in the array has cols size.
    
    for (int i = 0; i < noRows; ++i) {
        table[i] = new int[noCols]; // each row has spaces for noCols
    }
    
    /** Set up Table Names **/
    
    colNames = new char*[noCols]; // a 1-d array with cols number of names
    
    int j=0;
    char c;
    
    for (int i=0; i < 100; i++) { //I am assuming that each name is no more than 100 characters
        colNames[i] = new char[100];
    }
    for (int i=0; i < noCols; i++) {
        cin.get(c); //read the first character
        j = 0;
        do {
            colNames[i][j] = c;
            j++;
            cin.get(c);
        } while ((c != ',') && (c != '\n'));
        colNames[i][j] = '\0';
    }
    
    rowNames = new char*[noRows]; // a 1-d array with rows number of names
    
    int k=0;
    char e;
    
    for (int i=0; i < 100; i++) { //I am assuming that each name is no more than 100 characters
        rowNames[i] = new char[100];
    }
    for (int i=0; i < noRows; i++) {
        cin.get(e); //read the first character
        k = 0;
        do {
            rowNames[i][k++] = e;
            cin.get(e);
        } while ((e != ',') && (e != '\n'));
        rowNames[i][k] = '\0';
    }
    
    for (int i=0; i < noRows; i++)
        for (int j=0; j < noCols; j++)
            cin >> table[i][j];
    
}

// using the display method, print (in the same format as the input):
// - the column names of the dataframe
// - the row names of the dataframe
// - the contents of the table in dataframe
void DataFrame::display() {

    /** Column names **/
    
    for (int i = 0; i < noCols; ++i) {
        cout << colNames[i];
        if (i != (noCols - 1)) {
            cout << ",";
        }
    }
    cout << endl;
    
    /** Row names **/
    
    for (int i = 0; i < noRows; ++i) {
        cout << rowNames[i];
        if (i != (noRows - 1)) {
            cout << ",";
        }
    }
    cout << endl;
    
    /** Table contents **/
    for (int i = 0; i < noRows; ++i) {
        for (int j = 0; j < noCols; ++j) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
}

void DataFrame::setRowName(int row, const char* name) {
    //    char c;
    //    int j;
    //    for (int i=0; i < noRows; i++) {
    //        cin.get(c); //read the first character
    //        j = 0;
    //        do {
    //            rowNames[i][j++] = c;
    //            cin.get(c);
    //        } while ((c != ',') && (c != '\n'));
    //        rowNames[i][j] = '\0';
    //        cout << rowNames[i] << endl;
    //    }
    
}

void DataFrame::setColName(int col, const char* name) {
    //    char c;
    //    int j;
    //    for (int i=0; i < noCols; i++) {
    //        cin.get(c); //read the first character
    //        j = 0;
    //        do {
    //            colNames[i][j++] = c;
    //            cin.get(c);
    //        } while ((c != ',') && (c != '\n'));
    //        colNames[i][j] = '\0';
    //        cout << colNames[i] << endl;
    //    }
    
    
}

int* DataFrame::operator[](int i) { // return row i
    return table[i]; // return row i
}

char** DataFrame::getRowNames() { // DONE: CHECK IT
    return rowNames;
}

char** DataFrame::getColNames() { // DONE: CHECK IT
    return colNames;
}

int DataFrame::getNumberRows() { // DONE: CHECK IT
    return noRows;
}

int DataFrame::getNumberCols() { // DONE: CHECK IT
    return noCols;
}
DataFrame* DataFrame::getColumns(int* columns, int cLen) {
    
    DataFrame* temp = new DataFrame();
    
    (*temp).noCols = cLen;
    (*temp).noRows = noRows;
    
    /** Set up the table itself **/
    
    (*temp).table = new int*[noRows]; // double pointers allow us to initialize an array of rows size where each element in the array has cols size.
    
    for (int i = 0; i < noRows; ++i) {
        (*temp).table[i] = new int[cLen]; // each row has spaces for cLen
    }
    
    /** Set up Table Names **/
    
    (*temp).colNames = new char*[cLen]; // a 1-d array with cols number of names

    for (int i=0; i < 100; i++) { //I am assuming that each name is no more than 100 characters
        (*temp).colNames[i] = new char[100];
    }
    
    (*temp).rowNames = new char*[noRows]; // a 1-d array with rows number of names
    
    for (int i=0; i < 100; i++) { //I am assuming that each name is no more than 100 characters
        (*temp).rowNames[i] = new char[100];
    }
    
        /** Column names **/
    for (int i = 0; i < cLen; ++i) {
        (*temp).colNames[i] = colNames[columns[i]];
    }
    
        /** Row names **/
    for (int i = 0; i < noRows; ++i) {
        (*temp).rowNames[i] = rowNames[i];
    }
    
    for (int i = 0; i < noRows; ++i) {
        for (int j = 0; j < cLen; ++j) {
            (*temp).table[i][j] = table[i][columns[j]];
        }
//        cout << endl;
    }

    return temp;
}

DataFrame* DataFrame::getRows(int* rows, int rLen) { // CHECK IF CORRECT!
    DataFrame *frame = new DataFrame(rLen, 0);
    
    for (int i = 0; i < rLen; ++i) {
        //        frame[i] = table[i];
    }
    return frame;
}
DataFrame* DataFrame::getRowsCols(int* rows, int rLen, int* cols, int cLen) {
    
    //    DataFrame *frame = new DataFrame(rLen, );
    return NULL;
}


DataFrame::~DataFrame() { //Destructor for table
    cout << "Table destroyed!" << endl;
}


int main () {
    int c, r;
    int selectC[3];
    int selectR[10];
    
    // Read the dataframe from input
    // First line: two numbers seperated by space;
    // first number is the number of rows (r) and
    // second number is the number of columns (c)
    
    cin >> r >> c;
    DataFrame* firstDF = new DataFrame(r,c);
    
    // Second line: strings separated by a comma (c of them); representing column names
    // Third line: strings seperated by a comma (r of them); representing row names
    // Fourth line and more: c number of integers in each of the r rows (seperated by) // a space between integers in the same row.
    
    // using the display method, print (in the same format as the input):
    // - the column names of the dataframe
    // - the row names of the dataframe
    // - the contents of the table in dataframe
    
    (*firstDF).display();
    
    // Execute the following code
    // Read the column numbers that you want to extract
    
    for (int i=0; i < 3; i++) cin >> selectC[i];
    
    DataFrame* tempColumns = (*firstDF).getColumns(selectC, 3);
    
    (*tempColumns).display();
    
    // Change the row names of select rows
    
//    (*tempColumns).setRowName(2, "Jack"); (*tempColumns).setRowName(3, "Peter");
//
//    (*tempColumns).display();
//
//    // Read the row numbers that you want to extract
//
//    for (int i=0; i < 10; i++) cin >> selectR[i];
//
//    DataFrame* tempRows = (*firstDF).getRows(selectR, 10);
//
//    (*tempRows).display();
//
//    // Change the column names of selected columns
//
//    (*tempRows).setColName(2, "Scores");
//    (*tempRows).setColName(3, "Values");
//
//    (*tempRows).display();
//
//    // Extract the rows in SelectR and columns in SelectC
//
//    DataFrame* tempColsRows = (*firstDF).getRowsCols(selectR, 10, selectC, 3);
//
//    (*tempColsRows).display();
//
//    delete tempRows;
//
//    delete tempColumns;
//
//    delete tempColsRows; // Sample Code for you and you must execute this DataFrame* myTable = new DataFrame(5,5); for (int i =0; i < 5; i++) { for (int j=0; j < 5; j++) { (*myTable)[i][j] = i*j; } } (*myTable).display(); delete myTable;
    
    return 0;
}

