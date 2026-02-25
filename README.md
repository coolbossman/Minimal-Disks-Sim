# Minimal Disks Simulation



This codebase was intended to simulate the motion of disks in a box, but it was not functional.



The first step in rectifying this was to recreate and re-reference the header files, along with re-adding a missing member function.

This was first done for the `system` class in the branch `*system-fix*`, then for the `disk` class in the branch `*disk-fix*` before these were both merged back into main.



However, the codebase failed to produce the expected results; visualising the outputs showed the disks teleporting around, much faster than they should be able to.



re-referenced system.h in main.cpp; system.cpp, readded missing member function from system.cpp, recreated system.h from the ref. manual, improved documentation in these files, updated progress in README.md



readded missing member function from disk.cpp, recreated disk.h from the ref. manual, improved documentation in these files.



compiled and ran, disks were teleporting, altered parameters slightly, bug remained, added debugging code to isolate bug to code or visualisation

