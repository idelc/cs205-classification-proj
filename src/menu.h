#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <ctime>
#include <string>

#include "data.h"
#include "search_algorithms.h"

using namespace std;

void mainMenu(){
    unsigned answer = 90;
//    unsigned row, col;
//    double* data;
    string filename = "";
    clock_t runTime;
    file_data fdat;

    while(answer != 0) {
        cout << "Welcome to the feature search program for CS205, Spring 2023" << endl << endl;
        cout << "Choose an option:\n";
        cout << "1. Run small forward\n";
        cout << "2. Run big forward\n";
        cout << "3. Run huge forward\n";
        cout << "4. Run small backward\n";
        cout << "5. Run big backward\n";
        cout << "6. Run new csv forward\n";
        cout << "7. Run new csv backward\n";
        cout << "0. Exit\n";
        cout << endl;
        cin >> answer;
        switch (answer) {
            case 1:
                cout << "Running small forward...";
                //            cin >> fileName;
                cout << endl;
                // get_file_dims_csv("data/norm_small_data-29.csv", row1, col);
                // data = (double *) malloc(sizeof(double)*row*col);
                // read_csv("data/norm_small_data-29.csv", data, row1, col);
                filename = "data/norm_small_data-29.csv";
                init_file_data(&fdat, filename);
                runTime = clock();
                forwardSelection(&fdat);
                cout << "\nCPU time (linux only): " << static_cast<double>((clock() - runTime)) / CLOCKS_PER_SEC
                     << " seconds" << endl;
                free(fdat.data);
                break;
            case 2:
                cout << "Running big forward...";
                //            cin >> fileName;
                cout << endl;
                // get_file_dims_csv("data/norm_big_data-2.csv", row1, col);
                // data = (double *) malloc(sizeof(double)*row*col);
                // read_csv("data/norm_big_data-2.csv", data, row1, col);
                filename = "data/norm_big_data-2.csv";
                init_file_data(&fdat, filename);
                runTime = clock();
                forwardSelection(&fdat);
                cout << "\nCPU time (linux only): " << static_cast<double>((clock() - runTime)) / CLOCKS_PER_SEC
                     << " seconds" << endl;
                free(fdat.data);
                break;
            case 3:
                cout << "Running huge forward...";
                //            cin >> fileName;
                cout << endl;
                // get_file_dims_csv("data/norm_huge_data-21.csv", row1, col);
                // data = (double *) malloc(sizeof(double)*row*col);
                // read_csv("data/norm_huge_data-21.csv", data, row1, col);
                filename = "data/norm_huge_data-21.csv";
                init_file_data(&fdat, filename);
                runTime = clock();
                forwardSelection(&fdat);
                cout << "\nCPU time (linux only): " << static_cast<double>((clock() - runTime)) / CLOCKS_PER_SEC
                     << " seconds" << endl;
                free(fdat.data);
                break;
            case 4:
                cout << "Running small backward...";
                //            cin >> fileName;
                cout << endl;
                // get_file_dims_csv("data/norm_small_data-29.csv", row1, col);
                // data = (double *) malloc(sizeof(double)*row*col);
                // read_csv("data/norm_small_data-29.csv", data, row1, col);
                filename = "data/norm_small_data-29.csv";
                init_file_data(&fdat, filename);
                runTime = clock();
                backwardElimination(&fdat);
                cout << "\nCPU time (linux only): " << static_cast<double>((clock() - runTime)) / CLOCKS_PER_SEC
                     << " seconds" << endl;
                free(fdat.data);
                break;
            case 5:
                cout << "Running big backward...";
                //            cin >> fileName;
                cout << endl;
                // get_file_dims_csv("data/norm_big_data-2.csv", row1, col);
                // data = (double *) malloc(sizeof(double)*row*col);
                // read_csv("data/norm_big_data-2.csv", data, row1, col);
                filename = "data/norm_big_data-2.csv";
                init_file_data(&fdat, filename);
                runTime = clock();
                backwardElimination(&fdat);
                cout << "\nCPU time (linux only): " << static_cast<double>((clock() - runTime)) / CLOCKS_PER_SEC
                     << " seconds" << endl;
                free(fdat.data);
                break;
            case 6:
                cout << "Name of file (ex: data/xx.csv): ";
                cin >> filename;
                cout << endl;
                // get_file_dims_csv(fileName, row1, col);
                // data = (double *) malloc(sizeof(double)*row*col);
                // read_csv(fileName, data, row1, col);
                init_file_data(&fdat, filename);
                runTime = clock();
                forwardSelection(&fdat);
                cout << "\nCPU time (linux only): " << static_cast<double>((clock() - runTime)) / CLOCKS_PER_SEC
                     << " seconds" << endl;
                free(fdat.data);
                break;
            case 7:
                cout << "Name of file (ex: data/xx.csv): ";
                cin >> filename;
                cout << endl;
                // get_file_dims_csv(fileName, row1, col);
                // data = (double *) malloc(sizeof(double)*row*col);
                // read_csv(fileName, data, row1, col);
                init_file_data(&fdat, filename);
                runTime = clock();
                backwardElimination(&fdat);
                cout << "\nCPU time (linux only): " << static_cast<double>((clock() - runTime)) / CLOCKS_PER_SEC
                     << " seconds" << endl;
                free(fdat.data);
                break;
            default:
                cout << "Bye!" << endl;
                exit(0);
                break;
        }
        cout << endl;
    }

}

#endif
