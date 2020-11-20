#!/bin/bash


for cfile in *.c
do
#sed -i -e 's/^struct\ \{/static struct {/g'
sed -i -e 's/^struct {/static struct {/g' $cfile
done