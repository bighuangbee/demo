go build

#export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib:/mnt/d/server/www/demo/keda/so
# so所在目录
#cgo LDFLAGS: -L/mnt/d/server/www/demo/keda/so -lMcuSDK_LinuxC
#cgo LDFLAGS: -L/usr/local/lib -lMcuSDK_LinuxC