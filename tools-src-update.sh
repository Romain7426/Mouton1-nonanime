#!/bin/sh -u -e 

rm -Rf tools

mkdir -p tools
mkdir -p tools/src
mkdir -p tools/build
mkdir -p tools/bin

cp -fp ../project-tools/src/*.c tools/src/
cp -fp ../project-tools/src/*.ci tools/src/

chmod -w tools/src/*.c
chmod -w tools/src/*.ci

