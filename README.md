# shuati

[![Build Status](https://travis-ci.com/xxks-kkk/shuati.svg?branch=master)](https://travis-ci.com/xxks-kkk/shuati)

This is the respository that I put my [systematic algorithm learning](https://github.com/xxks-kkk/algo)
into practice by solving various interview questions. This is also the place where I learn different programming languages.

## Steps to developing a usable algorithm.

- Model the problem.
- Find an algorithm to solve it.
- Fast enough? Fits in memory?
- If not, figure out why not.
- Find a way to address the problem.
- Iterate until satisfied

## Usage

To build all C, C++ solutions, run

``` shell
$ mkdir -p build && cd build && cmake .. && make -j4
```

To build Java solutions, find `Makefile` inside the directory that program resides, and run `make`

To build all Rust solutions, run

``` shell
$ cd leetcode/rust
$ cargo test
```

