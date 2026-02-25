#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include "system.h"
// HINT: COMPLETE THE INCLUDE STATEMENT


/**
 * @brief Entry point of the program.
 *
 * This function initializes the program and manages execution.
 */
int main() {
    // number of disks
    int N = 20;
    double maxDisplacement = 0.4;
    double diskRadius = 0.5;
    double L = 20.0;

    // initialise the system
    System system(N, maxDisplacement,diskRadius,L,1234);

    // total number of iterations
    int iterations = N*500;

    for (int i = 0; i < iterations; ++i) {
        // move one disk
        system.step();
        // save a configuration
        std::ostringstream fname;
        fname << "confs/conf" << std::setw(5) << std::setfill('0') << i;
        system.save(fname.str());
    }

    // Save system parameters to a file
    std::ofstream paramFile("params");
    paramFile << "N=" << N << "\n";
    paramFile << "maxDisplacement=" << maxDisplacement << "\n";
    paramFile << "diskRadius=" << diskRadius << "\n";
    paramFile << "L=" << L << "\n";
    paramFile.close();

    return 0;
}