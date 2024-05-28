- Linux
  Linux也是一个操作系统，我在学习大数据的时候就开始用到它了，比如说hadoop，spark一些部署，会用到。
  我是使用VM装iso镜像装的linux。会配置基本的网络，像桥接模式、nat模式等
  在linux中我平时用得比较多的命令。
  比如ls查看文件，cd、cp、mv等，chmod和chown改权限的，ssh远程登录服务器，scp传文件这些，less或者cat看文件，vi、vim编写文件、ps、top查看进程信息。
  解压tar.gz等文件也会解压。 还有yum、wget下载文件。   为了方便我有时候会用xshell等来控制linux。
  在里面也会经常用到/etc这个目录下的配置文件，比如 配置环境变量，网络信息啊等
  我买过阿里云部署过宝塔来玩linux，部署了一个基于Django的个人博客项目

- Requests
  Requests是我初学爬虫时候用的最多的模块，发请求比较方便吧，封装了urlib。
  比如requests.get(url)可以获取网页内容，requests.post(url, data)可以提交表单数据
  但是缺点是后面编写 协程啊异步什么的比较繁琐。所以我后面就比较喜欢用Scrapy了。这个框架是基于异步的，存储什么的管道都会分类好

- Selenium
  Selenium一般用来做网页的自动化，模拟登录啥的
  其实像有时候有些爬虫遇见麻烦的反爬虫会用到selennium，但是还是速度比较慢。会尽量去使用JS逆向

- Docker
  Docker用来快速部署很好。可以用docker build构建镜像，用docker run启动容器。比如有时候要测试一个应用，用Docker打包好，发给同事，他们直接docker run就可以跑起来，不用再纠结环境问题。

- FastAPI
  FastAPI是用来快速构建API服务的，写起来特别简洁。用@app.get()、@app.post()这些装饰器定义接口，然后uvicorn.run(app)启动服务。之前做过一个小项目，用FastAPI写了几个接口，速度很快，性能也不错。

- K8s
  K8s其实我不是很熟，但听说是用来管理容器的。可以自动部署、扩展和管理应用。比如你可以用kubectl apply -f部署应用，用kubectl get pods查看运行状态。听说很多大公司都在用这个来做微服务管理，自动化水平很高。

- Langchain
  Langchain也是属于听说过的，貌似是用来处理复杂文本生成的。可以用Chain.run()来运行任务，Pipeline.add()添加处理步骤。感觉对做自然语言处理项目挺有帮助的，但具体怎么用我也不是很清楚
  我相信我可以在工作中很快学会用这些工具。

- 关系型数据库
  平时用得最多的数据库应该就是MySQL和PostgreSQL了。写SQL语句SELECT、INSERT、UPDATE、DELETE这些基本操作，还有JOIN用来连接表。平时做项目查数据、插数据都离不开这些SQL命令。
  但是我后面用Django有orm框架，它貌似更安全了。

- 非关系型数据库
  非关系型数据库主要用MongoDB和Redis。MongoDB用来存一些结构不固定的数据，像用db.collection.find()查询数据，db.collection.insert()插入数据。Redis一般用来做缓存，速度很快，像用set和get存取数据，特别适合处理高并发的场景。

> 这些都是我平时接触和用到的一些技术，谢谢。