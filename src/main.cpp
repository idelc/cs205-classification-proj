// #include "k_nearest_neighbors.h"
#include "nn.h"
#include "menu.h"
#include "reader.h"
#include "search_algorithms.h"
#include <ostream>

int test_nn();

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

    test_nn();

    return 0;
}

int test_nn() {
    string small_file = "data/CS170_small_Data__29.txt";
    std::vector<int> feat = {1, 3, 5};

    // NOTE: THESE ARE PROVIDED TEST SAMPLES
    // DO NOT EDIT THESE
    // string small_file = "test_data/CS170_small_Data__32.txt";
    // std::vector<int> feat = {1, 3, 5};
    // string small_file = "test_data/CS170_small_Data__33.txt";
    // std::vector<int> feat = {8, 7, 3};
    // string small_file = "test_data/CS170_large_Data__32.txt";
    // std::vector<int> feat = {3, 7, 6};
    // string small_file = "test_data/CS170_large_Data__33.txt";
    // std::vector<int> feat = {4, 5, 10};

    file_data fdat;
    init_file_data(&fdat, small_file);

    cout << "Small File Data has " << fdat.total_dpts << " data points and " <<
        fdat.dpt_size << " features per data point." << endl;

    cout << "feature is: " << get_data_at(&fdat, 6, 5) << endl;
    cout << "feature is: " << get_data_at(&fdat, 1, 0) << endl;
    cout << "feature is: " << get_data_at(&fdat, 1, 1) << endl;
    cout << "feature is: " << get_data_at(&fdat, 1, 2) << endl;
    cout << "feature is: " << get_data_at(&fdat, 1, 5) << endl;

    cout << "classes are: " << classes_match(&fdat, 6, 5) << endl;
    cout << "classes are: " << classes_match(&fdat, 1, 0) << endl;
    cout << "classes are: " << classes_match(&fdat, 1, 1) << endl;
    cout << "classes are: " << classes_match(&fdat, 1, 2) << endl;
    cout << "classes are: " << classes_match(&fdat, 1, 5) << endl;


    cout << "distances are: " << compute_distance(&fdat, feat, 6, 5) << endl;
    cout << "distances are: " << compute_distance(&fdat, feat, 1, 0) << endl;
    cout << "distances are: " << compute_distance(&fdat, feat, 1, 1) << endl;
    cout << "distances are: " << compute_distance(&fdat, feat, 1, 2) << endl;
    cout << "distances are: " << compute_distance(&fdat, feat, 1, 5) << endl;

    double accuracry = nn_eval(&fdat, feat);
    cout << "accuracy was: " << accuracry << endl;

    return 1;
}
