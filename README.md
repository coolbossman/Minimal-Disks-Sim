# Minimal Disks Simulation

---

This codebase was intended to simulate the motion of disks in a box, but it was not functional.

---

The first step in rectifying this was to recreate and re-reference the header files, along with re-adding a missing member function.

This was first done for the `system` class in the branch *`system-fix`*, then for the `disk` class in the branch *`disk-fix`* before these were both merged back into main.

---

However, the codebase failed to produce the expected results; visualising the outputs showed the disks teleporting around, much faster than they should be able to, along with the disks clipping into the walls. 

Both issues involved the distance checks working off of the disks' centre and not including their radius, but the teleporting was also due to python reading in lexographic order (0, 1, 10, 100 etc) instead of numerical (0, 1, 2 etc) and so was displaying frames out of order. 

All of these discoveries were completed within the `main-test` branch, which, upon verification that functionality had been restored, would be merged back into *`main`*.

---

With the functionality restored, focus then moved to additions and stress-testing, on the branch *`additions`*.

The appearance of the simulation was changed to stand out more, axis labels, a frame counter and a legend of the chosen parameters were added.

Further additional features added include command line arguments for adjusting the parameters on the fly, along with the clearing of the confs folder each time to facilitate this, a clock to track execution time, simple error checking for said adjustable parameters.

When these were completed, they were merged back into *`main`*.

---

Now completed, this codebase generates an iterative simulation of the motion of hard rigid disks on a flat bounded surface in the form of a series of files containing coordinate information.

The data than it produces can be visualised through the use of `matplotlib` in *python*.

To do so, the code must be compiled (C++17 or later, with gcc: `g++ -std=c++17 *.cpp`), and can be ran with the following parameters, N (int): number of disks; maxDisplacement (double): disk's speed; diskRadius (double): same scale as L; L (double): bounding box size.

Once executed, the data will be available in the `'./confs'` folder (create if necessary) and can be visualised by running either the *python3* script `view.py` or the only cell in the *Jupyter Notebook* `view.ipynb`.


