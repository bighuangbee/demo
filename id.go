
package main

import (
"fmt"
"os"

"github.com/bwmarrin/snowflake"
)

func main() {
	n, err := snowflake.NewNode(2)
	if err != nil {
		println(err)
		os.Exit(1)
	}

	for i := 0; i < 30; i++ {
		id := n.Generate()
		fmt.Println("id", id, id.Int64(), id.String())
		fmt.Println(
			"node: ", id.Node(),
			"step: ", id.Step(),
			"time: ", id.Time(),
			"\n",
		)
	}
}
