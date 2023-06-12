#include "k_nearest_neighbors.h"
#include "menu.h"
#include "reader.h"
#include "search_algorithms.h"

int main(){
    // test bench
    unsigned row = 0, col = 0;
    string small_file = "data/norm_small_data-29.csv";
    string large_file = "data/norm_big_data-2.csv";
    string huge_file = "data/norm_huge_data-21.csv";

    get_file_dims_csv(small_file, row, col);
    cout << "For file " << small_file << " got: " << row << " rows and " << col << " columns" << endl;
    double* arr1;
    arr1 = (double *) malloc(sizeof(double)*row*col);
    read_csv(small_file,arr1);
    cout << arr1[0] << ' ' << arr1[1] << ' ' << arr1[(row*col)-2] << ' ' << arr1[(row*col)-1] << endl;
//    int tmp_cnt = 0;
//    for(unsigned i = 0; i < row; i++){
//        for(unsigned j = 0; j < col; j++){
//            cout << arr1[tmp_cnt++] << ", ";
//        }
//        cout << endl;
//    }

    free(arr1);

    get_file_dims_csv(large_file, row, col);
    cout << "For file " << large_file << " got: " << row << " rows and " << col << " columns" << endl;
    arr1 = (double *) malloc(sizeof(double)*row*col);
    read_csv(large_file,arr1);
    cout << arr1[0] << ' ' << arr1[1] << ' ' << arr1[(row*col)-2] << ' ' << arr1[(row*col)-1] << endl;
    free(arr1);

    get_file_dims_csv(huge_file, row, col);
    cout << "For file " << huge_file << " got: " << row << " rows and " << col << " columns" << endl;
    arr1 = (double *) malloc(sizeof(double)*row*col);
    read_csv(huge_file,arr1);
    cout << arr1[0] << ' ' << arr1[1] << ' ' << arr1[(row*col)-2] << ' ' << arr1[(row*col)-1] << endl;
    free(arr1);

    return 0;
}