
package worker

//通过chan实现互斥锁
type Mutex struct {
	m chan struct{}
}

func NewMutex() *Mutex {
	m :=  &Mutex{
		m: make(chan struct{}),
	}

	go m.run()
	return m
}

func (m *Mutex) Lock() {
	m.m <- struct{}{}
}

func (m *Mutex) Unlock() {
	<-m.m
}

func (m *Mutex) run() {
	for {
		select {
			case <- m.m:
				m.m <- struct{}{}
		}
	}
}

