# Leetcode

Save my solutions to leecode problems

### Release of `local_leetcode`!!!

Visit public repository of [local leetcode](https://github.com/yuhenghuang/local_leetcode) for more information!!!



EVERYTHING BELOW IS OUTDATED!!!

EVERYTHING BELOW IS OUTDATED!!!

EVERYTHING BELOW IS OUTDATED!!!


### Shift to `utils3` seamlessly

**MAJOR UPDATE!!**

Support problems where the input is pair of method name and arguments' string!

Try 

```cpp
void main() {
  UFUNCX(
    CTOR(...)
    &cls::method1, 
    &cls::method2, 
    ...
  );
}
```

, where `CTOR()` wraps up the input types of constructor.


See problem *295* for example!

For inputs, use `','` to separate methods and arguments, NOT `';'` (first step to dispose `';'`)

By this update, the library now supports 99% of problems on leetcode to run AUTOMATICALLY
on local machine.

The shell script to further simplify manual work will be released recently (maybe python script?)

For more information, plz check the source.

P.S. 
* `UFUNC` in `utils2` remains the same.
* The complete disposal of `';'` is not done yet.
* Still dependent on many classes and functions in `utils2`.


### Shift to `utils2`

* Cleaner

* etc.

### Features

* past features ignored..

* Read/Parse inputs from files. `Tree`, `vector<T>`, `LinkedList` currently supported...

* Able to print datatypes (`Tree`, `vector<T>`, `LinkedList`) without `operator<<` defined...

* Add *./addinputs.sh* for convenience... e.g. `./addinputs.sh xxx_xxxx.cpp`

* Add `readlines` macro for *cpp*, further simplifying reading parameters from files.

* Add `vector<ListNode*>` and `vector<TreeNode*>` specialization

* Handle `string` properly
  * Support parsing `string` with spaces
  * Print `string` along side with quotes `"`.

* Allocate linear memory for `ListNode*` and `TreeNode*` efficiently.

* Handle memory properly by using `input_parameter` class as smart pointer for `ListNode*` and `TreeNode*`.


### Major update of *cpp*

For majority of questions in leetcode, now can be run by simply by

```cpp
void main() {
  UFUNC(Solution::method_name);
}
```

* `RUN` is deprecated now. please ALWAYS use `UFUNC` instead.

* `UFUNC` will call `RUN` internally if *cpp* is older than `c++14` for downward compatibility.

* *./addinputs.sh* will not check back to *cpp* or *java* file after input txt file is created.

* Able to record execution time inside of `UFUNC`. ( not applied for downward compatible `RUN`).

* *./addpairs.sh* reads clipboard to create well-formatted *cpp* file as well as input file. Try it.


### Plans for verion 3

* Cleaner input. Instead of using `';'` to split parameters, the new version plans to split parameters in a smarter way. That is, even when the parameters are split by `','`, the parser is able to distinguish between `','`s in parameters and as delimiters based on input parameters' types. (Easier than expected, only need to distinguish btw scalar and array-like types)

* Support problems where there are multiple methods called multiple times. There are two big challenges

  * *cpp* does not support pointer to constructors. This means it's impossible to obtain the types of parameters for the constructor. One potential solution is to use a helper function, while this might require some tricks on shell script to automate the process. (Class Factory)

  * How to choose from multiple member function pointers by `string`. May need an organic combination of MACRO and shell script (Polymorphic)

  * Minor challenge: parser for the input. This one is directly linked to **cleaner input** since there is no way one can replace delimiters by `';'` manually if the input contains thousands of characters. (Parse from left to right, using mechanism similar to calling stack to match parentheses)
