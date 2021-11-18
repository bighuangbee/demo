all: proto

.PHONY: all grpc micro

grpc:
	rm -rf proto/pb  && mkdir -p proto/pb
	protoc --experimental_allow_proto3_optional --plugin=grpc --proto_path=./proto --go_out=./ --go-grpc_out=./ user.proto;

micro:
	rm -rf proto/micro  && mkdir -p proto/micro
	protoc --experimental_allow_proto3_optional --plugin=micro --proto_path=. --micro_out=./ proto/user.proto

app_src = main.go
build_dir = deploy

app:
	rm -rf deploy && mkdir -p deploy
	cd src/app && CGO_ENABLED=0 GOOS=linux GOARCH=amd64 go build -tags netgo -ldflags="-w -s" -o ../../deploy/its_license main.go && \
	cp -rf conf ../../deploy/ && cp Dockerfile ../../deploy/ && cp ../../Shanghai ../../deploy/

