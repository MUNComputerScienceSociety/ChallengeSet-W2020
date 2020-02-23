package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func checkRow(row []int, valid chan bool) {
	foundVals := make([]bool, 9)

	for _, value := range row {
		foundVals[value-1] = true
	}

	for _, value := range foundVals {
		if !value {
			valid <- false
			return
		}
	}
	valid <- true
}

func checkColumn(grid [][]int, column int, valid chan bool) {
	values := make([]int, 0)
	for y := 0; y < 9; y++ {
		values = append(values, grid[y][column])
	}
	checkRow(values, valid)
}

func checkSquare(grid [][]int, square int, valid chan bool) {
	values := make([]int, 0)
	startX := (square % 3) * 3
	startY := (square / 3) * 3
	for x := startX; x < startX+3; x++ {
		for y := startY; y < startY+3; y++ {
			values = append(values, grid[y][x])
		}
	}
	checkRow(values, valid)
}

func main() {
	reader := bufio.NewReader(os.Stdin)

	rowChan := make(chan bool, 9)
	columnChan := make(chan bool, 9)
	squareChan := make(chan bool, 9)

	grid := make([][]int, 0)

	for i := 0; i < 9; i++ {
		text, _ := reader.ReadString('\n')
		digits := strings.Split(strings.TrimSuffix(text, "\n"), " ")
		line := make([]int, 0)

		for _, space := range digits {
			val, err := strconv.Atoi(space)
			if err != nil {
				fmt.Println(err)
				os.Exit(1)
			}
			line = append(line, val)
		}
		grid = append(grid, line)
		go checkRow(line, rowChan)
	}

	for x := 0; x < 9; x++ {
		go checkColumn(grid, x, columnChan)
		go checkSquare(grid, x, squareChan)
	}

	for i := 0; i < 9; i++ {
		if !<-rowChan || !<-columnChan || !<-squareChan {
			fmt.Println("invalid")
			os.Exit(0)
		}
	}
	fmt.Println("valid")

}
