#!/usr/bin/env bash

for entry in target/tests/*
do
  if [[ !($entry == *"test_compiler") && (-f $entry) ]]; then
    ./$entry
  fi
done