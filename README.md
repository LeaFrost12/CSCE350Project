**Lea Frost
**CSCE 350 Final Project

Instructions for compilation:

Run all commands from the root directory ("Project")

For running quick sort on a specific input file:
1. run "make"
2. then run "./Frost_Lea_QuickSort  <input_file_path> <output_file_path>"
The output file can have any name as it will be created upon running. Ensure that pathing is correct and from the root directory. For input, do "input/<input_file>". For output, do "output/<output_file>".

For average time calculation:
"make run" will clean extra files, generate 25 input files for each size (10,100,100), run quicksort on each file, store each output in a separate file, populate the execution time file, and calculate the average execution time for each size.

The input directory contains the generate input files.
The output directory contains the sorted output files, the execution time file, and average execution time file.
