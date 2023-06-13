#include "nn.h"
#include "reader.h"
#include <float.h>
#include <ostream>

#define CLASS_INDEX 0
// #define DEBUG_MODE

// Initialize the file data struct
void init_file_data(file_data *fdat, std::string filename) {
    get_file_dims_ssf(filename, fdat->total_dpts, fdat->dpt_size);
    fdat->data = (double *)malloc(sizeof(double) * fdat->dpt_size * fdat->total_dpts);
    read_ssf(filename, fdat->data);
}

// Compute the accuracy using sel_features as a distance metric 
double nn_eval(file_data *fdat, std::vector<int> sel_feat) {
    int accuracy = 0;
    // Test each point (by leaving it out)
    for (int i = 0; i < fdat->total_dpts; i++) {
        #ifdef DEBUG_MODE
          cout << "Starting new point: Class: " << get_data_at(fdat, i, 0) << endl;
        #endif
        int closest_pt = 0;
        double min_dist = DBL_MAX;
        // find the closest point to the target point at idx i
        for(int j = 1; j < fdat->total_dpts; j++) {
            // skip the target point from consideration
            if (j == i) continue;
            // find the distance based on select features
            double dist = compute_distance(fdat, sel_feat, i, j);
            if (dist < min_dist) {
                #ifdef DEBUG_MODE
                  cout << "distance updated to node " << j << ": " << dist << " from " << min_dist << " class: " << get_data_at(fdat, i, 0) << endl;
                #endif
                closest_pt = j;
                min_dist = dist;
            }
        }
        // if the classes of the closest point and target point, i,
        // match, then knn has accurately classified the value.
        // so increment the accuracy
        if (classes_match(fdat, i, closest_pt)) {
            accuracy++;
        }
    }
    return (accuracy + 0.0) / fdat->total_dpts;
}


// Check to see if the classes of data points x and y match
bool classes_match(file_data *fdat, int x, int y) {

    int x_class = get_data_at(fdat, x, CLASS_INDEX);
    int y_class = get_data_at(fdat, y, CLASS_INDEX);

    return x_class == y_class;
}


// compute the euclidean distance between points x and y based on
// the requested features
// NOTE: Don't compute the squareroot at the end as it's not necessary
double compute_distance(file_data *fdat, std::vector<int> sel_feat, int x, int y) {
    // initialize the distance
    double dist = 0;
    // sum the dot prod of each vector of values
    for(int feat : sel_feat) {
        double x_feat = get_data_at(fdat, x, feat); 
        double y_feat = get_data_at(fdat, y, feat); 
        // compute the distance
        dist += (x_feat - y_feat) * (x_feat - y_feat);
    }

    // Square root is not computed as it's not necessary
    // for this application
    return dist;
}


// Fetch the data from some index given some feature
double get_data_at(file_data *fdat, int idx, int feat) {
    return fdat->data[(idx*fdat->dpt_size) + feat];
}
