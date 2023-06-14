#ifndef READER_H
#define READER_H

#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <algorithm>

// referenced
// count: https://stackoverflow.com/questions/3867890/count-character-occurrences-in-a-string-in-c

using namespace std;

struct file_data {
    unsigned dpt_size;
    unsigned total_dpts;
    double *data;
};

// initialize the file_data struct
void init_file_data(file_data *, string);

// void get_file_dims_csv(string fN, unsigned& rows, unsigned& cols);
void get_file_dims_csv(file_data *, string);
void read_csv(file_data *, string);

#endif
// void get_file_dims_csv(string fN, unsigned& rows, unsigned& cols ){
//     ifstream read(fN);
//     string tLine;
//     double temp = 0;
//     rows = 0;
//     cols = 0;

//     if(!read.is_open()){
//         cout << "Error opening " << fN << endl;
//         exit(1);
//     }

//     getline(read, tLine);
//     cols = count(tLine.begin(), tLine.end(), ',') + 1; // count number of decimals in our data, same as counting rows

//     while(read){
//         rows++;
//         getline(read, tLine);
//     }
// }

// // pass in file name, rows, and columns, if one or more of the size arguments 0,
// // find them before reading the file
// // should return a double pointer to data
// // this works for the files given in class which are not csv
// // assume array has already been allocated perfectly
// void read_csv(string fName, double store_array[], unsigned& rows, unsigned& cols){
//     ifstream read(fName);
//     double temp = 0;
//     char comTemp;
//     unsigned long cnt = 0, lm = 0;

//     if(!read.is_open()){
//         cout << "Error opening " << fName << endl;
//         exit(1);
//     }
//     get_file_dims_csv(fName, rows, cols);
//     lm = (rows*cols) - 1;
// //    cout << "here1" << endl;
//     while(read && (cnt < lm)){
//         for(unsigned i = 0; i < (cols - 1); i++){
//             read >> temp >> comTemp;
//             store_array[cnt++] = temp;
// //            cout << temp << endl;
//         }
//         read >> temp;
//         store_array[cnt++] = temp;
//     }
// //    cout << "here2" << endl;
// //    cout << "saw: " << cnt << endl;
// }

// #endif

// void get_file_dims_ssf(string fN, unsigned& rows, unsigned& cols ){
//     ifstream read(fN);
//     string tLine;
//     double temp = 0;
//     rows = 0;
//     cols = 0;
//
//     if(!read.is_open()){
//         cout << "Error opening " << fN << endl;
//         exit(1);
//     }
//
//     getline(read, tLine);
//     cols = count(tLine.begin(), tLine.end(), '.'); // count number of decimals in our data, same as counting rows
//
//     while(read){
//         rows++;
//         getline(read, tLine);
//     }
// }
//
// // pass in file name, rows, and columns, if one or more of the size arguments 0,
// // find them before reading the file
// // should return a double pointer to data
// // this works for the files given in class which are not csv
// // assume array has already been allocated perfectly
// void read_ssf(string fName, double store_array[]){
//     ifstream read(fName);
//     double temp = 0;
//     unsigned long cnt = 0;
//
//     if(!read.is_open()){
//         cout << "Error opening " << fName << endl;
//         exit(1);
//     }
//
//     while(read){
//         read >> temp;
//         store_array[cnt++] = temp;
//     }
// }

