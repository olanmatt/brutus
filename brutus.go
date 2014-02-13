package main

import "fmt"

var arr []string

func main(){
	// array
	arr = make([]string,0)
	force("abcdefghijklmnop", 7, "", func(thisString string){
		/// array += thisString
		arr = append(arr, thisString)
		//fmt.Println(thisString);
	})
	fmt.Println(arr)
}

func force(str string, n int, thisString string, callback func(thisString string)){
	if n == 0 {
		callback(thisString);
		return;
	}

	for _, v := range(str) {
		force(str, n-1, thisString + string(v), callback)
	}
}
