# Dynamic-BF-Index
Dynamic Bloom Filter that can dynamically resize to maintain a low probability of false-positives.

## Purpose
Design and implement a Bloom Filter that can maintain a minimum performance specification while also minimizing the rate at which false positives can occur. The maximum probability of false positives can be defined, and the filter will resize and add/remove hash functions as needed. As such, **the rate at which false positives can occur is controllable**, and the **memory/compute complexity of the bloom filter is also controllable**.

## A Short Summary of Bloom Filters
Bloom filters are probabalistic data structures that are useful for determining whether a set contains an element. It is very space efficient, as the underlying data structure that the Bloom Filter uses is an array of bits, but this comes at the cost of introducing false positives, and it can potentially be computationally expensive to query the filter, depending on the number of hash functions. Hash functions are a core element of any Bloom Filter implementation, as elements being inserted/queried with the Bloom Filter are hashed, and the resulting hash value corresponds to the index that a given element exists in. With ```n``` hash functions, an element being inserted into the Filter will be hashed n times and will occupy/flip ```n``` bits in the underlying array. 

### False-positives
For a bloom filter with an underlying array of size, ```m```, and a number of hash functions, ```k```, provided there are ```j``` insertions, has a probability of false positives that is defined by: (1 - e^[-kn/m])^k

As such, for a bloom filter occupying 1MB of memory, using three hash functions, and containing 10000 elements (insertions), the probability of a false positive is 1 in 19,069,897 (1 / 0.000000052).

For a database with millions or billions of accesses at a time, this is unacceptable. However, for indexing small file systems, such a small memory footprint and low false-positive probability is very impressive. The potential for scalability is also impressive. For a user who wants to maintain the same probability of 1 in 19 million, but with a much larger amount of elements, 319,104, the memory footprint only increases to 32MB.

## Objectives
- [x] Create a working Bloom Filter implementation in Python
- [ ] Port the working implementation to C++
- [ ] Port the working implementation to Java
- [ ] Port the working implementation to Rust
- [ ] Perform benchmarks and empirical runtime analysis on each implementation
- [ ] Use matplotlib to create figures and diagrams showing the differences in runtime
- [ ] Modify the Bloom Filter so that it can dynamically resize 