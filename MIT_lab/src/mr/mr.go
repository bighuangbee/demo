package mr

import (
	"encoding/json"
	"errors"
	"fmt"
	"hash/fnv"
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

func Map(contents string) []*KeyValue {
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

func DoMap1(filename string, mapTaskIndex int, nReduce int)(maps[]*KeyValue, err error){

	content, err := ioutil.ReadFile(filename)
	if err != nil{
		return nil, err
	}

	kvs := make(map[int][]*KeyValue, 0)
	kva := Map(string(content))
	for _, v := range kva{
		reduceIndex := ihash(v.Key) % nReduce
		kvs[reduceIndex] = append(kvs[reduceIndex], v)
	}

	sort.Sort(KeyValueSort(kvs[0]))

	for reduceIndex, v := range kvs{
		a,_ := json.Marshal(v)
		ioutil.WriteFile(genMapName(mapTaskIndex, reduceIndex), a, 0755)
	}

	return nil, nil
}

func DoMap(filename string, mapTaskIndex int, nReduce int)(maps[]*KeyValue, err error){
	if nReduce <= 0{
		return nil, errors.New("DoMap nReduce=0")
	}

	encoders := make([]*json.Encoder, nReduce)
	for i := range encoders {
		f, err := os.Create(genMapName(mapTaskIndex, i))
		if err != nil {
			fmt.Println(err)
		}
		encoders[i] = json.NewEncoder(f)
		defer f.Close()
	}

	content, err := ioutil.ReadFile(filename)
	if err != nil{
		return nil, err
	}

	kva := Map(string(content))
	for _, v := range kva{
		reduceIndex := ihash(v.Key) % nReduce
		err := encoders[reduceIndex].Encode(v)
		if err != nil{
			fmt.Println(err)
		}
	}
	return
}

func genMapName(taskMapIndex, reduceIndex int)string{
	return fmt.Sprintf(OutputPath + "map-out-%d-%d", taskMapIndex, reduceIndex)
}

func genReduceName(reduceIndex int)string{
	return fmt.Sprintf(OutputPath + "reduce-out-%d", reduceIndex)
}

func ihash(s string) int {
	h := fnv.New32a()
	h.Write([]byte(s))
	return int(h.Sum32() & 0x7fffffff)
}


func DoReduce1(kvs []*KeyValue)(countKV []*WordCount){

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



func DoReduce(mapTaskNumber int, reduceTaskIndex int){

	kvs := make(map[string][]string)
	for mapTaskIndex := 0; mapTaskIndex < mapTaskNumber; mapTaskIndex++{
		file, err := os.Open(genMapName(mapTaskIndex, reduceTaskIndex))
		if err != nil{
			fmt.Println("DoReduce:", err)
		}

		decorder := json.NewDecoder(file)
		var item KeyValue
		for decorder.More() {
			err := decorder.Decode(&item)
			if err == nil{
				kvs[item.Key] = append(kvs[item.Key], item.Value)
			}else{
				fmt.Println("decorder:", err)
			}
		}
	}

	keys := []string{}
	for k, _ := range kvs{
		keys = append(keys, k)
	}
	sort.Strings(keys)

	file, err := os.Create(genReduceName(reduceTaskIndex))
	if err != nil{
		fmt.Println(err)
	}

	encorder := json.NewEncoder(file)
	for _, key := range keys{
		encorder.Encode(&KeyValue{
			Key:   key,
			Value: Reduce(key, kvs[key]),
		})
	}
	return
}
