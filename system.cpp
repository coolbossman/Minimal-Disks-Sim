#include <fstream>
#include "system.h"
#include "disk.h"

System::System(int N, double displacement,double radius, double boxSize, int seed) {
/** 
 * Simulates a system with N disks of given radius, placed in a box of given size.
 * Initially the disks are placed on a grid to prevent overlap, 
 * and then they are moved randomly in each step, checking for overlaps and boundaries.
 */
        this->boxSize= boxSize;
        this->  dist = std::uniform_real_distribution<double>(0, 1);
        this->displacement=displacement;
        gen = std::mt19937(seed);
        // function used here is the Mersenne Twister 
        // random number generator, chosen for its long period. 
        
        int nSide = static_cast<int>(boxSize/ (2*radius));

        for (int i = 0; i < nSide && disks.size() < N; ++i) {
            for (int j = 0; j < nSide && disks.size() < N; ++j) {
                disks.push_back(Disk(radius + i * 4*radius, radius + j * 4*radius, radius));
        }
    }   
}

bool System::overlap(int i){
    for (int j = 0; j < disks.size(); ++j) {
        if (i!=j && disks[i].distance(disks[j]) < 0.0 ) {
            return true;
        }
    }
    return false;
}

void System::step() {
    // move each disk randomly and check and revert overlaps
    for (size_t i=0; i<disks.size(); ++i) 
    {
        int selected_disk = std::rand() % disks.size();
        double oldx = disks[selected_disk].x;
        double oldy = disks[selected_disk].y;
        double dx = uniform(-displacement, displacement);
        double dy = uniform(-displacement, displacement);
        this->disks[selected_disk].move(dx, dy);
        
        
        enforceBoundaries(disks[selected_disk]);

        // isolating teleporting bug to code or visualisation
        if (overlap(selected_disk)){
            disks[selected_disk].x = oldx;
            disks[selected_disk].y = oldy;
        disks[selected_disk].x = oldx;
        disks[selected_disk].y = oldy;
        }
    }
}

void System::enforceBoundaries(Disk & disk) {
    // prevent disks from moving outside the box
        if ((disk.x - disk.radius) < 0.0) disk.x = disk.radius;
        if ((disk.x + disk.radius) > boxSize) disk.x = boxSize - disk.radius;
        if ((disk.y - disk.radius) < 0.0) disk.y = disk.radius;
        if ((disk.y + disk.radius) > boxSize) disk.y = boxSize - disk.radius;
}

double System::uniform(double min, double max) {
    // return a uniform number to move the disk to simulate Brownian motion 
    return min + (max - min) * dist(gen);
}

void System::save(const std::string &filename){
    // save state of disks to file
    std::ofstream outFile(filename);
    outFile<<disks.size()<<std::endl;
    outFile<<"Comment"<<std::endl;
    for (Disk& disk : disks) {
      outFile<<"A "<<disk.x<<" "<<disk.y<<" "<<disk.radius<<std::endl;

    }
    outFile.close();
    
}