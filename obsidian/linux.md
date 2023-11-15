## 常用功能
- ls
- **service**
	service xxx start
	service xxx stop
- systemctl
- sz/rz 文件传输
	rz 上传文件
	- -b 以二进制上传文件
- apt
	- download 下载安装包
	- install 安装软件
	- search 搜索

- iftop
	- 查看网络流量大小

- iperf3
	- 测试带宽
### 代码调试
- 性能分析
	- 内存泄露
		- vargrid
	- cpu
	- 磁盘
	- 网络
- gdb
- 


## 内存寻址

- 分段寻址
	- 段描述符
	- 段描述表
- 分页寻址
	- 逻辑地址 -> 物理地址

## network
- epoll
[[./network#^linux-epoll|network > ^linux-epoll]]
- select
### socket编程

```c
sock = scoket();

```

### 各类子系统

[[./WSL|WSL]]

[[./docker|docker]]