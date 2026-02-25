# Minimal Disks Simulation



This codebase was intended to simulate the motion of disks in a box, but it was not functional.



The first step in rectifying this was to recreate and re-reference the header files, along with re-adding a missing member function.

This was first done for the `system` class in the branch `*system-fix*`, then for the `disk` class in the branch `*disk-fix*` before these were both merged back into main.



However, the codebase failed to produce the expected results; visualising the outputs showed the disks teleporting around, much faster than they should be able to, along with the disks clipping into the walls. 

Both issues involved the distance checks working off of the disks' centre and not including their radius, but the teleporting was also due to python reading in lexographic order (0, 1, 10, 100 etc) instead of numerical (0, 1, 2 etc) and so was displaying frames out of order. 

All of these discoveries were completed within the `main-test` branch, which, upon verification that functionality had been restored, would be merged back into `main`.



With the functionality restored, focus then moved to additions and stress-testing.





re-referenced system.h in main.cpp; system.cpp, readded missing member function from system.cpp, recreated system.h from the ref. manual, improved documentation in these files, updated progress in README.md

readded missing member function from disk.cpp, recreated disk.h from the ref. manual, improved documentation in these files.

compiled and ran, disks were teleporting, altered parameters slightly, bug remained, added debugging code to isolate bug to code or visualisation, tweaked .gitignore to include .out/.o files, updated progress in README.md

debugging code showed a code issue, visual inspection showed a doubled radius check. boundary radius checks were added to prevent clipping around the edges. teleporting remained.

bug identified as mismatch between numerical/lexographical order, fixed with equal length filenames. project deemed functional.

visualisation changes: animation spruced up, legend; title added, data preloaded.



