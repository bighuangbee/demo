package main

type IMonitor interface {
	Cameras()(error)
}

type MonitorAuth struct {
	Addr string
	Appkey string
	AppSecret string
}

type HikVision struct {
	*MonitorAuth
}

func (h *HikVision)Cameras(v *MonitorAuth)IMonitor{
	return IMonitor
}

type mfunc func(v *MonitorAuth)interface{}
var ms map[string]mfunc

func pool(m IMonitor)  {
	m.Cameras()
}

func main() {

	hik := MonitorAuth{
		Addr:      "11",
		Appkey:    "22",
		AppSecret: "33",
	}

	ms = make(map[string]mfunc, 0)
	ms["hik"] = NewHikVision

	m1 := ms["hik"]
	ff := m1
	res := ff(&hik)
	v := res.(int)

}