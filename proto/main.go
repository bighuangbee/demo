/**
 * @desc //TODO $
 * @param $
 * @return $
 **/
package main

import (
	"bytes"
	"demo/proto/pb/proto"
	"fmt"
	"github.com/golang/protobuf/jsonpb"
)

func main()  {
	age := int32(22)
	//addr := "1"
	e1 := proto.Example{
		Name:   "",
		Age:    &age,
		//Addr:   nil,
		Blance: nil,
	}

	if e1.Addr == nil{
		fmt.Println("addr nil")
	}else if *e1.Addr == ""{
		fmt.Println("addr empty string")
	}else {
		fmt.Println("addr val:", *e1.Addr)
	}

	jsonpbMarshaler := &jsonpb.Marshaler{
		EnumsAsInts : true, //是否将枚举值设定为整数，而不是字符串类型
		EmitDefaults: true, //是否将字段值为空的渲染到JSON结构中
		OrigName    : true, //是否使用原生的proto协议中的字段
	}

	addr := ""
	e2 := proto.Example{
		Name:   "bighuangbee",
		Age:    nil,
		Addr:   &addr,
	}
	var buffer  bytes.Buffer
	jsonpbMarshaler.Marshal(&buffer, &e2)
	fmt.Println(string(buffer.Bytes()))

}


