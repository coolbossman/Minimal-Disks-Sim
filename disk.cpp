#include "disk.h"
#include <cmath>

Disk::Disk(double x, double y, double r){
    this->x = x;
    this->y = y;
    this->radius = r;
}

void Disk::move(double dx, double dy){
    this->x += dx;
    this->y += dy;
}

double Disk::distance(Disk& other){
    // returns the distance between the two disks boundaries
    double dx = this->x - other.x;
    double dy = this->y - other.y;
    double center_distance = sqrt(dx*dx + dy*dy);
    double edge_distance = center_distance - (this->radius + other.radius);

    return edge_distance;
    // HINT: COMPLETE THE CALCULATION OF THE DISTANCE BETWEEN this DISK AND THE DISK other

}