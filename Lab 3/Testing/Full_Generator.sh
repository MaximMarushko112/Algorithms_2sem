#!/usr/bin/bash
from=$1
to=$2
step=$3
i=$from
while [ $i -le $to ]
do
j=1
while [ $j -le 5 ] 
do
name="{$i}_{$j}"
touch very_small_tests/$name.in
./Test_Generator.exe $i 32768 $RANDOM > very_small_tests/$name.in
touch very_small_tests/$name.out
./Answer_Generator.exe $i < very_small_tests/$name.in > very_small_tests/$name.out
j=$(( $j + 1 ))
done
i=$(( $i + $step ))
done
