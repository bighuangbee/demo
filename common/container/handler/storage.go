package handler

type Storage struct {
	Name   string
	Ak     string
	Sk     string
	Bucket string
	Url    string
}

type IStorage interface {
	GetPicturePreViewURL()(url string, err error)
}