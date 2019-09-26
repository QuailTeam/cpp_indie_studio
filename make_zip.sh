#!/bin/bash

rm -rf release
mkdir release
cp -R indie_studio .conf_ignore res icon.png libs/* release

rm indie.zip
cd release
zip -r indie.zip *
mv indie.zip ..
cd ..
