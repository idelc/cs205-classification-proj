#include "k_nearest_neighbors.h"
#include "menu.h"
#include "reader.h"
#include "search_algorithms.h"

int main(){
    // test bench
    unsigned row = 0, col = 0;
    string small_file = "data/CS170_small_Data__29.txt";
    string large_file = "data/CS170_large_Data__2.txt";
    string huge_file = "data/CS170_XXXlarge_Data__21.txt";

    get_file_dims_ssf(small_file, row, col);
    cout << "For file " << small_file << " got: " << row << " rows and " << col << " columns" << endl;
    double* arr1;
    arr1 = (double *) malloc(sizeof(double)*row*col);
    read_ssf(small_file,arr1);
    cout << arr1[0] << ' ' << arr1[1] << ' ' << arr1[(row*col)-2] << ' ' << arr1[(row*col)-1] << endl;
    free(arr1);

    get_file_dims_ssf(large_file, row, col);
    cout << "For file " << large_file << " got: " << row << " rows and " << col << " columns" << endl;
    arr1 = (double *) malloc(sizeof(double)*row*col);
    read_ssf(large_file,arr1);
    cout << arr1[0] << ' ' << arr1[1] << ' ' << arr1[(row*col)-2] << ' ' << arr1[(row*col)-1] << endl;
    free(arr1);

    get_file_dims_ssf(huge_file, row, col);
    cout << "For file " << huge_file << " got: " << row << " rows and " << col << " columns" << endl;
    arr1 = (double *) malloc(sizeof(double)*row*col);
    read_ssf(huge_file,arr1);
    cout << arr1[0] << ' ' << arr1[1] << ' ' << arr1[(row*col)-2] << ' ' << arr1[(row*col)-1] << endl;
    free(arr1);

    return 0;
}