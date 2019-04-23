### To test what will happen if an inline function in the header file calls a function that has only been included in the implementation of this header
The result is the program succeeds at executing as expected.
In the phase of preprocessing, preprocessor will remove comments, expand macros and include all the files, so the function that has not yet been included in the header will be included after this step. 
