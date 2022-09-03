package goSolution

import (
	"bufio"
	"fmt"
	"os"
)

func Solve_1722C() {
	var t, n int
	br := bufio.NewReader(os.Stdin)
	bw := bufio.NewWriter(os.Stdout)
	defer bw.Flush()
	fmt.Fscan(br, &t)
	words := make([][]string, 3)
	for i := 0; i < 3; i++ {
		words[i] = make([]string, 1000)
	}
	for t > 0 {
		t--
		fmt.Fscan(br, &n)
		word2cnt := make(map[string]int, 0)
		for i := 0; i < 3; i++ {
			for j := 0; j < n; j++ {
				fmt.Fscan(br, &words[i][j])
				word2cnt[words[i][j]]++
			}
		}
		score := make([]int, 3)
		for i := 0; i < 3; i++ {
			for j := 0; j < n; j++ {
				switch word2cnt[words[i][j]] {
				case 1:
					{
						score[i] += 3
					}
				case 2:
					{
						score[i] += 1
					}
				}
			}
		}
		fmt.Fprintf(bw, "%d %d %d\n", score[0], score[1], score[2])
	}
}
