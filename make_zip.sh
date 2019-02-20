#!/bin/bash

rm -rf release
mkdir release
cp -R indie_studio res icon.png release
rm indie.zip
cd release
zip -r indie.zip *
mv indie.zip ..
cd ..
