package main

import (
	"fmt"
	"github.com/extrame/xls"
	"github.com/tealeg/xlsx"
	"log"
	"os"
)

var xlsxTitle = []string{"字段1", "字段2", "字段3", "字段4"}
var cell *xlsx.Cell

func main() {

	pwd, _ := os.Getwd()
	//targetPath := pwd + `\房地产.xlsx`
	//xlsxFile := getXlsxFile(targetPath)
	//xlsxSheet := xlsxFile.Sheets[0]
	//
	//dataToInsert := []string{"切片内数据1", "切片内数据2", "切片内数据3", "切片内数据4"}
	//insertRow(xlsxSheet, &dataToInsert)
	//xlsxFile.Save(targetPath)


	xlsPath := pwd + `/房地产.xls`
	f, err := xls.Open(xlsPath, "utf-8")
	if err != nil {
		log.Fatal(err)
	}
	// 获取xls文件的第一个sheet
	sheet := f.GetSheet(0)
	// 从第二行开始，遍历xls文件，然后按行调用insertRowFromXls函数
	for j := 1; j < int(sheet.MaxRow)+1; j++ {
		xlsRow := sheet.Row(j)
		rowColCount := xlsRow.LastCol()
		for i := 0; i < rowColCount; i++ {
			fmt.Println(i, xlsRow.Col(i))
		}
	}


	xlsxPath := pwd + `/房地产.xlsx`
	xlsxFile, err1 := xlsx.OpenFile(xlsxPath)
	if err1 != nil{
		log.Fatal(err1)
	}
	sheet1 := xlsxFile.Sheets[0]
	for k := 1; k < sheet1.MaxRow; k++{
		row := sheet1.Row(k)
		for i := 0; i < len(row.Cells); i++{
			fmt.Println(i, row.Cells[i])
		}
	}
}

// 将一个切片指针对应的数据插入到xlsx.sheet中
func insertRow(sheet *xlsx.Sheet, rowDataPtr *[]string) {
	row := sheet.AddRow()
	rowData := *rowDataPtr
	for _, v := range rowData {
		cell := row.AddCell()
		cell.Value = v
	}

}

// 获取xlsx.File对象的指针，如果文件路径不存在则新建一个文件，并返回其指针
func getXlsxFile(filePath string) *xlsx.File {
	var file *xlsx.File
	if _, err := os.Stat(filePath); err == nil {
		file, err = xlsx.OpenFile(filePath)
		if err != nil {
			log.Fatal(err)
		}

	} else {
		file = xlsx.NewFile()
		sheet, err := file.AddSheet("sheet1")
		if err != nil {
			log.Fatal(err)
		}
		insertRow(sheet, &xlsxTitle)
	}

	return file

}