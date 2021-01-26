# Leetcode

Save my solutions to leecode problems


### Shift to `utils2`

* Cleaner

* etc.

### Features

* past features ignored..

* Read/Parse inputs from files. `Tree`, `vector<T>`, `LinkedList` currently supported...

* Able to print datatypes (`Tree`, `vector<T>`, `LinkedList`) without `operator<<` defined...

* Add *./addinputs.sh* for convenience... e.g. `./addinputs.sh xxx_xxxx.cpp`

* Add `readlines` macro for *cpp*, further simplifying reading parameters from files.

* Add `vector<ListNode*>` specialization


### Major update of *cpp*

For majority of questions in leetcode, now can be run by simply

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
