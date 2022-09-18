# Object Tracer

This project contains the object tracer used in the Advanced Programming course at the University of Antwerp.
The Doxygen documentation can be found [here](https://www.thomasave.be/object-tracer/).

## Running the tracer

Create a build folder and enter it:

    mkdir build
    cd build
  
Run CMake and compile the program:

    cmake ..
    make
  
Install the program to the `installed` directory:

    make install
  
Run the object tracer:

    ./installed/bin/tracer 
  
You should now get a list of exercises to choose from:

    The available exercises are:

      copy
      essentialops
      exam_2021_1
      exam_2021_2
      exception
      fcalls
      hierarchies
      poly1
      poly2

    Select a demo by name: 

Simply type one of the names followed by pressing enter, and the trace should be logged to stdout!


## Adding new tracing exercises

1. Copy an existing file in `src/exercises/` and rename it, e.g. `test.cpp`
2. Inside the file rename the name of the function containing the trace to name of the file: `app_test()`
3. Add the file to the library in [`src/exercises/CMakeLists.txt`](src/exercises/CMakeLists.txt)
5. In [`src/exercises/demos.h`](src/exercises/demos.h), add your new trace function: `int app_trace();`
6. In [`main.cpp`](src/main.cpp), add your function to the function register: `f_reg["test"] = app_test` near line 42;
7. Rerun `cmake ..` and `make install`
8. When executing `./installed/bin/tracer` now, your file should be one of the options to trace, and you can log the trace of your file!
