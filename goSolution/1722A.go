package goSolution

import (
	"fmt"
	"sort"
)

func Solve_1722A() {
	var t, n int
	var name string
	fmt.Scan(&t)
	for t > 0 {
		fmt.Scan(&n)
		fmt.Scan(&name)
		if n != 5 {
			fmt.Println("NO")
		} else {
			na := []byte(name)
			sort.Slice(na, func(i, j int) bool { return na[i] < na[j] })
			if string(na) == "Timru" {
				fmt.Println("YES")
			} else {
				fmt.Println("NO")
			}
		}
		t--
	}
}
