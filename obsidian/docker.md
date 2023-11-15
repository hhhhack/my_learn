### docker 常用命令
docker build -f
docker images 查看本地镜像
docker search \[name\] 查找
docker build \[-t\] \[name:tag\] path 通过docker file构建镜像
docker image rm \[-f\] 删除镜像
docker -it  -v \[local_dir:docker_dir\]  --name dockername -p docker_port:local_port \[imageid\] /bin/bash运行

### dockerfile
from - 指定基础镜像
add/copy  \[--chown\] \[--chmod\] - 拷贝文件到镜像,支持远程文件，文件需要在当前目录下，或者绝对路径，add支持解压缩

### 安装
`curl -fsSL https://get.docker.com | bash -s docker --mirror Aliyun`
