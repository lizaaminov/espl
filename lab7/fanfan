#!/bin/sh

echo $PATH

y=`find ~ -name "*.c" | xargs grep -l main`
for x in $y;
do
echo $x
echo =============================================
grep -A 6 -w -n main $x
echo =============================================
done
