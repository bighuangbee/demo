package handler

import "fmt"

type CosStorage struct {
	*Storage
}


func NewCosClient(s *Storage)(cos *CosStorage){
	fmt.Println("NewCosClient", *s)
	s.Url += " ** cos"
	return &CosStorage{s}
}

func (s *CosStorage)GetPicturePreViewURL()(url string, err error){
	fmt.Println("GetPicturePreViewURL CosStorage", *s)

	s.Url += " * CosStorage"
	return s.Url, nil
}