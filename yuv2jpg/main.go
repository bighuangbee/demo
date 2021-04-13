/**
 * @desc //TODO $
 * @param $
 * @return $
 **/
package main

import (
	"fmt"
	"gocv.io/x/gocv"
	"io/ioutil"
)

func main(){
	data, err := ioutil.ReadFile("yuv.txt")
	if err != nil {
		fmt.Println(err)
		return
	}

	width := 640
	height := 480

	yuvMat, err := gocv.NewMatFromBytes(height*3/2, width, gocv.MatTypeCV8UC1,  data)
	if err != nil {
		fmt.Println(err)
		return
	}

	gocv.NewMat()

	var SrcImgGray = gocv.NewMat()

	gocv.CvtColor(yuvMat, &SrcImgGray, gocv.ColorYUVToRGBYV12);




	fmt.Println( "readImage",yuvMat.Size(), len(yuvMat.ToBytes()), len(SrcImgGray.ToBytes()))
	gocv.IMWrite("img.jpg", SrcImgGray)
}


//cv::Mat yuv420Torgb(unsigned char *yuvdata, int width, int height) {
////    uchar *yuvdata = new uchar[height * 3 / 2 * width * sizeof(uchar)];
////    fread(yuvdata, height * 3 / 2, width, fp);
//cv::Mat yuvimg(height * 3 / 2, width, CV_8UC1, yuvdata);
//cv::Mat rgbimg(height, width, CV_8UC3);
//cvtColor(yuvimg, rgbimg, cv::COLOR_YUV2BGR_NV21);
//return rgbimg;
//}