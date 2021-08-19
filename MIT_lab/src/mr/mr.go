package mr

import (
	"errors"
	"io/ioutil"
	"os"
	"sort"
	"unicode"
)
import "strings"
import "strconv"

const OutputPath = "../../output/"

func init(){
	os.Mkdir(OutputPath, 0755)
}

func Map(filename string, contents string) []*KeyValue {
	ff := func(r rune) bool { return !unicode.IsLetter(r) }

	words := strings.FieldsFunc(contents, ff)

	kva := []*KeyValue{}
	for _, w := range words {
		kv := KeyValue{w, "1"}
		kva = append(kva, &kv)
	}
	return kva
}

func Reduce(key string, values []string) string {
	return strconv.Itoa(len(values))
}


func DoMap(filenames []string)(maps[]*KeyValue, err error){
	errs := ""
	for _, filename := range filenames {
		content, err := ioutil.ReadFile(filename)
		if err != nil {
			errs = "cannot read %v" + filename +","
		}
		kva := Map(filename, string(content))
		maps = append(maps, kva...)
	}
	sort.Sort(KeyValueSort(maps))

	if len(errs) > 0{
		return maps, errors.New(errs)
	}
	return
}

func DoReduce(kvs []*KeyValue)(countKV []*WordCount){

	sort.Sort(KeyValueSort(kvs))

	i := 0
	for i < len(kvs) {
		j := i + 1
		for j < len(kvs) && kvs[j].Key == kvs[i].Key {
			j++
		}
		values := []string{}
		for k := i; k < j; k++ {
			values = append(values, kvs[k].Value)
		}

		count := Reduce(kvs[i].Key, values)

		countKV = append(countKV, &WordCount{
			Key:   kvs[i].Key,
			Value: count,
		})

		i = j
	}
	return
}



func DoReduce1(kvs []*KeyValue)(countKV []*WordCount){
	kvsMap := make(map[string][]*KeyValue, 0)
	for _, val := range kvs{
		kvsMap[val.Key] = append(kvsMap[val.Key], val)
	}

	keys := make([]string, 0, len(kvsMap))
	for k, _ := range kvsMap {
		keys = append(keys, k)
	}
	sort.Strings(keys)

	for _, key := range keys{
		countKV = append(countKV, &WordCount{Key: key, Value:strconv.Itoa(len(kvsMap[key]))})
	}
	return
}
