# shuati

[![Build Status](https://travis-ci.com/xxks-kkk/shuati.svg?branch=master)](https://travis-ci.com/xxks-kkk/shuati)

This is the respository that I put my [systematic algorithm learning](https://github.com/xxks-kkk/algo)
into practice by solving various interview questions. This is also the place where I practice different programming languages.

## Steps to developing a usable algorithm.

- Model the problem.
- Find an algorithm to solve it.
- Fast enough? Fits in memory?
- If not, figure out why not.
- Find a way to address the problem.
- Iterate until satisfied

## Usage

The repo contains a mixture of different programming languages. To build and test solutions written in specific
language, follow steps below:

### C, C++

To build all C, C++ solutions, run

``` shell
$ mkdir -p build && cd build && cmake .. && make -j4
```

### Java

To build Java solutions, find `Makefile` inside the directory that program resides, and run `make`

### Rust

To test all Rust solutions, run

``` shell
$ cd rust
$ cargo test
```

