#!/bin/bash

masterAddr="localhost:2001"

go run master.go $masterAddr &

sleep 0.1

workerAddr1="localhost:3001"
go run worker.go $masterAddr $workerAddr1 &

workerAddr2="localhost:3002"
go run worker.go $masterAddr $workerAddr2 &

wait
