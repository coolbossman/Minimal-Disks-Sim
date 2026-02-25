#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <filesystem>
#include <iomanip>
#include <chrono>
#include "system.h"


/**
 * @brief Entry point of the program.
 *
 * This function initializes the program and manages execution.
 */
int main(int argc, char* argv[]) {
    
    // number of disks
    int N = 20;

    double maxDisplacement = 2.0;
    double diskRadius = 0.5;

    // box size
    double L = 20.0;

    // command-line arguments
    if (argc > 1) N = std::atoi(argv[1]);
    if (argc > 2) maxDisplacement = std::atof(argv[2]);
    if (argc > 3) diskRadius = std::atof(argv[3]);
    if (argc > 4) L = std::atof(argv[4]);

    bool valid = true;
    std::string error_msg;

    // Use switch to check each parameter by index
    for (int i = 1; i < argc; ++i) {
        int param_type = (i == 1 || i == 4) ? 0 : 1;  // 0 for int, 1 for double
        switch (param_type) {
            case 0:  // int parameters (N)
                {
                    std::stringstream ss(argv[i]);
                    int val;
                    if (!(ss >> val) || !ss.eof()) {
                        valid = false;
                        error_msg = "Error: Parameter " + std::to_string(i) + " must be a valid integer.";
                    } else {
                        if (i == 1) N = val;
                        // Additional checks
                        if ((i == 1 && N <= 0)) {
                            valid = false;
                            error_msg = "Error: Parameter " + std::to_string(i) + " must be positive/non-negative.";
                        }
                    }
                }
                break;
            case 1:  // double parameters (maxDisplacement, diskRadius, L)
                {
                    std::stringstream ss(argv[i]);
                    double val;
                    if (!(ss >> val) || !ss.eof()) {
                        valid = false;
                        error_msg = "Error: Parameter " + std::to_string(i) + " must be a valid number.";
                    } else {
                        if (i == 2) maxDisplacement = val;
                        else if (i == 3) diskRadius = val;
                        else if (i == 4) L = val;
                        // Additional checks
                        if (val <= 0) {
                            valid = false;
                            error_msg = "Error: Parameter " + std::to_string(i) + " must be positive.";
                        }
                    }
                }
                break;
        }
        if (!valid) break;
    }

    if (!valid) {
        std::cerr << error_msg << std::endl;
        return 1;  // Exit with error code
    }


    // total number of iterations
    int iterations = N*500;

    // output chosen parameters
    std::cout << "Using parameters: N = " << N << ", maxDisplacement = " << maxDisplacement 
              << ", diskRadius = " << diskRadius << ", L = " << L << ", totalIterations = " << iterations << std::endl;

    // initialise the system
    System system(N, maxDisplacement,diskRadius,L,1234);

    auto start = std::chrono::high_resolution_clock::now();

    // clear ./confs
    for (const auto& entry : std::filesystem::directory_iterator("confs")) {
        if (entry.is_regular_file()) {
            std::filesystem::remove(entry.path());
        }
    }

    for (int i = 0; i < iterations; ++i) {
        // move one disk
        system.step();
        // save a configuration
        std::ostringstream fname;
        fname << "confs/conf" << std::setw(5) << std::setfill('0') << i;
        system.save(fname.str());
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Execution time: " << elapsed.count() << " seconds" << std::endl;

    // Save system parameters to a file
    std::ofstream paramFile("params");
    paramFile << "N=" << N << "\n";
    paramFile << "maxDisplacement=" << maxDisplacement << "\n";
    paramFile << "diskRadius=" << diskRadius << "\n";
    paramFile << "L=" << L << "\n";
    paramFile.close();

    return 0;
}