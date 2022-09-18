# Object Tracer

This project contains the object tracer used in a C++ programming course at the University of Antwerp.
The Doxygen documentation can be found [here](https://www.thomasave.be/prog2/).


## Adding new tracing exercises

1. Copy an existing file in `src/exercises/` and rename it, e.g. `test_trace.cpp`
2. Inside the file rename the name of the function containing the trace to name of the file: `test_trace()`
3. Add the file to the sources in [`src/exercises/CMakeLists.txt`](CMakeLists.txt) on lines 60-61
4. Add the function to the projects in [`src/exercises/CMakeLists.txt`](CMakeLists.txt) on lines 69-70
5. In [`demos.h`](demos.h), add your new trace function: `int test_trace();`
6. In [`app_exec.cpp`](app_exec.cpp), add your function to the function register: `f_reg["test_trace"] = test_trace`;
7. Rerun make all; make install; make test;.
8. When executing `app_exec` now, your file should be one of the options to trace, and you can log the trace of your file!
