#!/bin/bash

export PATH=/opt/gcc-10.1/bin/:$PATH
export LD_LIBRARY_PATH=/opt/gcc-10.1/lib:/opt/gcc-10.1/lib64:$LD_LIBRARY_PATH

# print current GCC version
g++ --version

