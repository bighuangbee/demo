package handler

import "fmt"

type OssStorage struct {
	*Storage
}

func NewOssClient(s *Storage)(cos *OssStorage){
	fmt.Println("NewCosClient", *s)
	s.Url += " ## oss"
	return &OssStorage{s}
}

func (s *OssStorage)GetPicturePreViewURL()(url string, err error){
	fmt.Println("GetPicturePreViewURL OssStorage ", *s)

	s.Url += " # OssStorage"
	return s.Url, nil
}