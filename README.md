# Leetcode

Save my solutions to leecode problems


### Features

* past features ignored..

* Read/Parse inputs from files. `Tree`, `vector<T>`, `LinkedList` currently supported...

* Able to print datatypes (`Tree`, `vector<T>`, `LinkedList`) without `operator<<` defined...

* Add *./addinputs.sh* for convenience... e.g. `./addinputs.sh xxx_xxxx.cpp`

* Add `readlines` macro for *cpp*, further simplifying reading parameters from files.


### Major update of *cpp*

For majority of questions in leetcode , now can be run by simply

```cpp
void main() {
  RUN(Solution::method_name);
}
```

* `RUN` is deprecated now. please use `UFUNC` instead.

* *./addinputs.sh* will not check back to *cpp* or *java* file after input txt file is created.
