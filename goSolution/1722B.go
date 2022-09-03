package goSolution

import (
	"fmt"
)

func Solve_1722B() {
	var t, n int
	fmt.Scan(&t)
	for t > 0 {
		t--
		fmt.Scan(&n)
		flag := true
		var s1, s2 string
		fmt.Scan(&s1)
		fmt.Scan(&s2)
		ss1 := []byte(s1)
		ss2 := []byte(s2)
		for i := range ss1 {
			if ss1[i] == ss2[i] || ss1[i] == 'G' && ss2[i] == 'B' || ss1[i] == 'B' && ss2[i] == 'G' {
				continue
			}
			flag = false
			break
		}
		if flag {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}
