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

func readBinaryWatch(num int) []string {
	return []string{}
}

// generateTimeBasedOnPos generates time representation
// based on pos, which has format [_,_,_,_,_,_,_,_,_,_] (an array of
// 10 digits): the first four digits represents '8','4','2','1' on the watch (1st position
// represents '8' and so on) and the rest six digits represents '32','16','8','4','2','1'
func generateTimeBasedOnPos(pos [10]int) string {
	return "8:00"
}
