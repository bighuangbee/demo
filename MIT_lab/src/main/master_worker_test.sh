#!/bin/bash

masterAddr="localhost:2001"

go run master.go $masterAddr ../../inputFile/* &

sleep 0.1

for i in {1..2} ; do
  workerAddr3="localhost:300"$i
  go run worker.go $masterAddr $workerAddr3 &
done

wait
