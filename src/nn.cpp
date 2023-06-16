#include "nn.h"
#include "data.h"
#include <algorithm>
#include <float.h>
#include <ostream>
#include <cmath>

#define CLASS_INDEX 0
// #define DEBUG_MODE


// Compute the accuracy using sel_features as a distance metric 
double nn_eval(file_data *fdat, std::vector<unsigned> sel_feat) {
    int total_correct = 0;
    // Test each point (by leaving it out)
    for (unsigned i = 0; i < fdat->total_dpts; i++) {
        #ifdef DEBUG_MODE
          cout << "Starting new point: Class: " << get_data_at(fdat, i, 0) << endl;
        #endif
        int closest_pt = 0;
        double min_dist = DBL_MAX;
        // find the closest point to the target point at idx i
        for(unsigned j = 1; j < fdat->total_dpts; j++) {
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
        // so increment the total_correct 
        if (classes_match(fdat, i, closest_pt)) {
            total_correct++;
        }
    }
    double accuracy = (total_correct + 0.0) / fdat->total_dpts;
    return std::max(accuracy, 1-accuracy);
    // return (accuracy + 0.0) / fdat->total_dpts;
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
double compute_distance(file_data *fdat, std::vector<unsigned> sel_feat, int x, int y) {
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
    return sqrt(dist);
}


// Fetch the data from some index given some feature
double get_data_at(file_data *fdat, int idx, int feat) {
    return fdat->data[(idx*fdat->dpt_size) + feat];
}
