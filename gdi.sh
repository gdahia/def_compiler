#!/bin/bash

if [[ $# != 1 ]]; then
    echo "Error: pass a def source file as input"
    exit
fi

./def_compiler.out $1 tmp.s
spim -f tmp.s
rm tmp.s
