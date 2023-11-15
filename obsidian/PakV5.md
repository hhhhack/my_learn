1. compressed single file
	1. 压缩文件到 `/data/v5_single/dat/h/filecontenthash[2]/filecontenthash[3]/contenthashstr.filesize`
	2. 判断是否是特殊文件，或者文件过小，这些文件不压缩，直接写到上面的地址。
	3. 生成v.detail文件和v文件

2. generate file list
	1. 读取v.detail信息
	2. 逐个遍历目录
	3. 写到datalist里
	4. 排除黑名单，不属于该平台的和打开成功的
	5. 特殊文件直接拷贝到包目录，写到single.csv
	6. 文件过大单独做一个包
	7. 当包文件足够大生成filelist
		1. 把v.detail的信息当成content，计算hash
		2. 按照下面这种格式保存
		```
			[hash_hashstr]
			compressed_filename\t compressedsize\t size\t namehash\t contenthash\n
			...
		```

1. 生成hpkg和version文件
	1. 根据filelist把文件组合起来
		1. 先写入索引文件头
		2. 再写入压缩后的文件信息
		3. 最后把文件信息写入
	2. 建立文件内容hash->文件信息列表的map
	3. 生成version文件
		1. 根据filenamehash计算索引，把文件信息加到 idx->文件信息set的map，
		2. 对文件加做同上操作
		3. 对hpkg文件做同样操作
		4. 上述操作把所有文件散列到65532个桶里
		5. 把每个桶里的文件信息生成一个hash值
		6. 按4096一份，把65532个桶分成16份，再把每份的内容写到文件里
		7. 把每个桶对应的hash和桶对应的文件数量写到文件里
		8. 再把大桶的对应信息写进去