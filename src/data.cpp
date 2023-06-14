#include "data.h"


// Initialize the file data struct
void init_file_data(file_data *fdat, std::string filename) {
    //get_file_dims_csv(filename, fdat->total_dpts, fdat->dpt_size);
    get_file_dims_csv(fdat, filename);
    fdat->data = (double *)malloc(sizeof(double) * fdat->dpt_size * fdat->total_dpts);
    // read_csv(filename, fdat->data);
    read_csv(fdat, filename);
    // read_csv(fdat, filename);
}


// Return the total number of rows and columns of a file
// void get_file_dims_csv(string fN, unsigned& rows, unsigned& cols ){
// void get_file_dims_csv(file_data *fdat, string fN){
//     ifstream read(fN);
//     string tLine;
//     double temp = 0;
//     // rows = 0;
//     // cols = 0;
//     int total_dpts = 0;
//
//     if(!read.is_open()){
//         cout << "Error opening " << fN << endl;
//         exit(1);
//     }
//
//     getline(read, tLine);
//     fdat->dpt_size = count(tLine.begin(), tLine.end(), '.'); // count number of decimals in our data, same as counting rows
//     // cols = count(tLine.begin(), tLine.end(), '.'); // count number of decimals in our data, same as counting rows
//
//     while(read){
//         // rows++;
//         total_dpts++;
//         getline(read, tLine);
//     }
//     fdat->total_dpts = total_dpts;
// }
//
// // pass in file name, rows, and columns, if one or more of the size arguments 0,
// // find them before reading the file
// // should return a double pointer to data
// // this works for the files given in class which are not csv
// // assume array has already been allocated perfectly
// // void read_csv(string fName, double store_array[]){
// void read_csv(file_data *fdat, string fName) {
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
//         // store_array[cnt++] = temp;
//         fdat->data[cnt++] = temp;
//     }
// }


// void get_file_dims_csv(string fN, unsigned& rows, unsigned& cols ){
void get_file_dims_csv(file_data *fdat, string fN){
    ifstream read(fN);
    string tLine;
//    double temp = 0;
    unsigned rows = 0;
    unsigned cols = 0;

    if(!read.is_open()){
        cout << "Error opening " << fN << endl;
        exit(1);
    }

    getline(read, tLine);
    cols = count(tLine.begin(), tLine.end(), ',') + 1; // count number of commas + 1 in our data, same as counting rows

    while(read){
        rows++;
        getline(read, tLine);
    }

    fdat->total_dpts = rows;
    fdat->dpt_size   = cols;
}

// pass in file name, rows, and columns, if one or more of the size arguments 0,
// find them before reading the file
// should return a double pointer to data
// this works for the files given in class which are not csv
// assume array has already been allocated perfectly
// void read_csv(string fName, double store_array[], unsigned& rows, unsigned& cols){
void read_csv(file_data *fdat, string fName) {
    ifstream read(fName);
    double temp = 0;
    char comTemp;
    unsigned long cnt = 0, lm = 0;

    if(!read.is_open()){
        cout << "Error opening " << fName << endl;
        exit(1);
    }
    // get_file_dims_csv(fName, rows, cols);
    // lm = (rows*cols) - 1;
    lm = (fdat->dpt_size * fdat->total_dpts) - 1;
//    cout << "here1" << endl;
    while(read && (cnt < lm)){
        // for(unsigned i = 0; i < (cols - 1); i++){
        for(unsigned i = 0; i < (fdat->dpt_size - 1); i++){
            read >> temp >> comTemp;
            fdat->data[cnt++] = temp;
//            cout << temp << endl;
        }
        read >> temp;
        fdat->data[cnt++] = temp;
    }
    
//    cout << "here2" << endl;
//    cout << "saw: " << cnt << endl;
}
