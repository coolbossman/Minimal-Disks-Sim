#ifndef DISK_H
#define DISK_H
// prevent double declaration

class Disk {
    /* 
    A simple class to represent a hard disk.
    */
public:
    double x, y, radius;
    Disk(double x, double y, double r) ;

    void move(double dx, double dy) ;
    double distance(Disk& d) ;
};

#endif // !DISK_H