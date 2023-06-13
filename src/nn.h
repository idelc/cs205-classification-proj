#ifndef NN_H
#define NN_H

#include <vector>
// #include "reader.h"

struct file_data {
    double *data;
    unsigned dpt_size;
    unsigned total_dpts;
};

// initialize the file data struct
void init_file_data(file_data *, std::string);

// Take in some data, which features you wish to select
// And the total number of data points that need to be processed
// and return the accuracy of the mode as a double
// perfoming k-nearest neighbors
double nn_eval(file_data *, std::vector<int>);

bool classes_match(file_data *, int, int);

double compute_distance(file_data *, std::vector<int>, int, int);

double get_data_at(file_data *, int, int);

#endif // NN_H
