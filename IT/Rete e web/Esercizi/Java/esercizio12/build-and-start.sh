#!/bin/bash

javac -cp .:/home/alessandro/Documenti/Jetty/jetty-distribution-9.4.6.v20170531/lib/* *.java

java -cp .:/home/alessandro/Documenti/Jetty/jetty-distribution-9.4.6.v20170531/lib/* TestHttpPost
