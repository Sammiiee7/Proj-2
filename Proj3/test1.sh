#!/bin/sh

set -v
./matrix_math -add A A
./matrix_math -sub A A
./matrix_math -mul B B
./matrix_math -eq  A A
./matrix_math -eq  B A
./matrix_math -T   A
