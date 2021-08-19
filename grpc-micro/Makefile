all: proto

.PHONY: all proto

proto:
	protoc -I . proto/helloworld.proto --go_out=plugins=grpc:./proto
	protoc --proto_path=./proto --micro_out=./proto --go_out=./proto helloworld.proto


app_src = main.go
build_dir = deploy

app:
	rm -rf deploy && mkdir -p deploy
	cd src/app && CGO_ENABLED=0 GOOS=linux GOARCH=amd64 go build -tags netgo -ldflags="-w -s" -o ../../deploy/its_license main.go && \
	cp -rf conf ../../deploy/ && cp Dockerfile ../../deploy/ && cp ../../Shanghai ../../deploy/

