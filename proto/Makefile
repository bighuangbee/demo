proto:
	protoc --proto_path=. --go_out=. --micro_out=./ --gorm_out=. *.proto
	#protoc --experimental_allow_proto3_optional --proto_path=. --go_out=. --micro_out=./ --gorm_out=. example.proto

micro:
	protoc --experimental_allow_proto3_optional --plugin=micro --proto_path=. --micro_out=. --go_out=. example.proto
	protoc --proto_path=. --micro_out=./ --go_out=./ example.proto
