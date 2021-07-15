package main

import "net/http"

func test(writer http.ResponseWriter, request *http.Request) {

}

func WithVersion(h http.HandlerFunc) ( http.HandlerFunc){
	return  func(w http.ResponseWriter, r *http.Request) {
		w.Header().Set("v", "112")
		h(w, r)
	}
}

func main() {
	http.HandleFunc("/", WithVersion(test))
	http.ListenAndServe(":8080", nil)
}
