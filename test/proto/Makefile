
build-proto:
#	protoc --experimental_allow_proto3_optional -I=./ --go_out=./pb --plugin=grpc example.proto
# -I 导入目录， :./proto 输出目录
	rm -f pb/*.pb.go

	protoc --experimental_allow_proto3_optional -I=./ --go_out=./pb --plugin=mirco example.proto