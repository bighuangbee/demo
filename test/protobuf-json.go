package main

import (
	"bytes"
	"encoding/json"
	"fmt"
	"github.com/gogo/protobuf/jsonpb"
	proto "test/proto/pb"
)


func main(){

	age := int32(22)
	addr := "广州"
	e1 := proto.Example{
		Name:   "bighuangbee",
		Age:    &age,
		Addr:   &addr,
		Blance: 100,
	}

	fmt.Println(fmt.Sprintf("Example 1, age isnull=%s, age value=%d, addr isnull=%s, addr=%s", e1.Age == nil, *e1.Age, e1.Addr == nil, *e1.Addr))

	e2 := proto.Example{}
	fmt.Println(fmt.Sprintf("Example 2, age isnull=%s, addr isnull=%s", e2.Age == nil,  e2.Addr == nil))


	test()
}

var data = []byte(`{
   "somefield1":"somevalue1",
   "somefield2": null
}`)

type Data struct {
	SomeField1 string
	SomeField2 json.RawMessage
}

func test() {
jsonpbMarshaler := &jsonpb.Marshaler{
	EnumsAsInts : true, // 是否将枚举值设定为整数，而不是字符串类型
	EmitDefaults: true, //是否将字段值为空的渲染到JSON结构中
	OrigName    : true, //是否使用原生的proto协议中的字段
}

age := int32(22)
e1 := proto.Example{
	Name:   "bighuangbee",
	Age:    &age,
}
var buffer  bytes.Buffer
jsonpbMarshaler.Marshal(&buffer, &e1)
fmt.Println(string(buffer.Bytes()))
}