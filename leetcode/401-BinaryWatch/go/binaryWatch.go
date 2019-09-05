package binaryWatch

// A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).
// Each LED represents a zero or one, with the least significant bit on the right.
// Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.

// Example:

// Input: n = 1
// Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]

// Note:

//     The order of output does not matter.
//     The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
//     The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".

import (
	"bytes"
	"errors"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func readBinaryWatch(num int) []string {
	var tmp []int
	var res [][]int
	var res_str []string
	res = backtrack(num, tmp, res)
	for _, pos := range res {
		conv_res, err := generateTimeBasedOnPos(pos)
		if err != nil {
			fmt.Fprintf(os.Stderr, "readBinarywatch: %v\n", err)
			os.Exit(1)
		}
		time := strings.Split(conv_res, ":")
		hour, err := strconv.Atoi(time[0])
		if err != nil {
			fmt.Fprintf(os.Stderr, "readBinarywatch: %v\n", err)
		}
		minutes, err := strconv.Atoi(time[1])
		if err != nil {
			fmt.Fprintf(os.Stderr, "readBinarywatch: %v\n", err)
		}
		if hour >= 12 || minutes >= 60 {
			continue
		}
		res_str = append(res_str, conv_res)
	}
	return res_str
}

// TODO: interesting to learn more about Go
func backtrack(num int, tmp []int, res [][]int) [][]int {
	//fmt.Printf("num: %d, tmp: %v, res: %v, 10-len(tmp): %v\n", num, tmp, res, 10-len(tmp))
	if num > 10-len(tmp) {
		//fmt.Println("hit1")
		return res
	} else if num == 0 {
		for len(tmp) < 10 {
			tmp = append(tmp, 0)
		}
		tmp2 := tmp
		res = append(res, tmp2)
		//fmt.Printf("res (num == 0): %v\n", res)
		//fmt.Println("hit2")
	} else {
		//fmt.Println("hit3")
		for _, i := range [...]int{0, 1} {
			if i == 1 {
				num -= 1
			}
			tmp := append(tmp, i)
			res = backtrack(num, tmp, res)
			//fmt.Printf("res (else): %v\n", res)
			tmp = tmp[:len(tmp)-1]
			//fmt.Printf("tmp:%v, len(tmp):%v\n", tmp, len(tmp))
		}
	}
	return res
}

// generateTimeBasedOnPos generates time representation
// based on pos, which has format [_,_,_,_,_,_,_,_,_,_] (an array of
// 10 digits): the first four digits represents '8','4','2','1' on the watch (1st position
// represents '8' and so on) and the rest six digits represents '32','16','8','4','2','1'
func generateTimeBasedOnPos(pos []int) (string, error) {
	if len(pos) != 10 {
		return "", errors.New("pos must have 10 items")
	}
	lookup_table := [...]int{8, 4, 2, 1, 32, 16, 8, 4, 2, 1}
	var hours, minutes int
	for idx, _ := range pos {
		if idx <= 3 {
			hours += pos[idx] * lookup_table[idx]
		} else {
			minutes += pos[idx] * lookup_table[idx]
		}
	}
	var res []string
	res = append(res, strconv.Itoa(hours))
	if minutes < 10 {
		var buf bytes.Buffer
		buf.WriteString("0")
		buf.WriteString(strconv.Itoa(minutes))
		res = append(res, buf.String())
	} else {
		res = append(res, strconv.Itoa(minutes))
	}
	return strings.Join(res, ":"), nil
}
