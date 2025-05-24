## Laboratory work VIII

Данная лабораторная работа посвещена изучению систем автоматизации развёртывания и управления приложениями на примере **Docker**

```sh
$ open https://docs.docker.com/get-started/
```

## Tasks

- [ ] 1. Создать публичный репозиторий с названием **lab08** на сервисе **GitHub**
- [ ] 2. Ознакомиться со ссылками учебного материала
- [ ] 3. Выполнить инструкцию учебного материала
- [ ] 4. Составить отчет и отправить ссылку личным сообщением в **Slack**

## Tutorial

```sh
$ export GITHUB_USERNAME=<имя_пользователя>
```

```
$ cd ${GITHUB_USERNAME}/workspace
$ pushd .
$ source scripts/activate
```

```sh
$ git clone https://github.com/${GITHUB_USERNAME}/lab07 lab08
$ cd lab08
$ git submodule update --init
$ git remote remove origin
$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab08
```

```sh
$ cat > Dockerfile <<EOF
FROM ubuntu:18.04
EOF
```

```sh
$ cat >> Dockerfile <<EOF

RUN apt update
RUN apt install -yy gcc g++ cmake
EOF
```

```sh
$ cat >> Dockerfile <<EOF

COPY . print/
WORKDIR print
EOF
```

```sh
$ cat >> Dockerfile <<EOF

RUN cmake -H. -B_build -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=_install
RUN cmake --build _build
RUN cmake --build _build --target install
EOF
```

```sh
$ cat >> Dockerfile <<EOF

ENV LOG_PATH /home/logs/log.txt
EOF
```

```sh
$ cat >> Dockerfile <<EOF

VOLUME /home/logs
EOF
```

```sh
$ cat >> Dockerfile <<EOF

WORKDIR _install/bin
EOF
```

```sh
$ cat >> Dockerfile <<EOF

ENTRYPOINT ./demo
EOF
```

```sh
$ docker build -t logger .
```

```sh
$ docker images
```

```sh
$ mkdir logs
$ docker run -it -v "$(pwd)/logs/:/home/logs/" logger
text1
text2
text3
<C-D>
```

```sh
$ docker inspect logger
```

```sh
$ cat logs/log.txt
```

```sh
$ gsed -i 's/lab07/lab08/g' README.md
```

```sh
$ vim .travis.yml
/lang<CR>o
services:
- docker<ESC>
jVGdo
script:
- docker build -t logger .<ESC>
:wq
```

```sh
$ git add Dockerfile
$ git add .travis.yml
$ git commit -m"adding Dockerfile"
$ git push origin master
```

```sh
$ travis login --auto
$ travis enable
```

## Report

```sh
$ popd
$ export LAB_NUMBER=08
$ git clone https://github.com/tp-labs/lab${LAB_NUMBER} tasks/lab${LAB_NUMBER}
$ mkdir reports/lab${LAB_NUMBER}
$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md
$ cd reports/lab${LAB_NUMBER}
$ edit REPORT.md
$ gist REPORT.md
```

## Homework

Выполнив установку Докера, создаём файл Dockerfile:
```
FROM ubuntu:18.04
RUN apt update
RUN apt  install -yy gcc g++ cmake
COPY . /solver_application
WORKDIR /solver_application
RUN cmake -H. -B_build -DDCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=_install
RUN cmake --build _build
RUN cmake --build _build --target install
ENV LOG_PATH=/home/logs/log.txt
VOLUME /home/logs
WORKDIR /solver_application/_build/
ENTRYPOINT ["./equation"]
```
Создаём файл .github/workflows/main.yml:
```
name: Actions
on:
  push:
    branches: [master]
  pull_request:
    branches: [master]

jobs: 
 build_Linux:

  runs-on: ubuntu-latest

  steps:
  - uses: actions/checkout@v4

  - name: Build the Docker
    run: docker build -t logger .

  - name: Put logs
    run: docker run -v "$(pwd)/logs/:/home/logs/" logger
```
Запускаем Докер локально:
```
$ sudo docker build -t logger .  
[+] Building 13.0s (14/14) FINISHED                                                                                                   docker:default
 => [internal] load build definition from Dockerfile                                                                                            0.0s
 => => transferring dockerfile: 424B                                                                                                            0.0s 
 => [internal] load metadata for docker.io/library/ubuntu:18.04                                                                                 3.7s 
 => [internal] load .dockerignore                                                                                                               0.0s
 => => transferring context: 2B                                                                                                                 0.0s 
 => [1/9] FROM docker.io/library/ubuntu:18.04@sha256:152dc042452c496007f07ca9127571cb9c29697f42acbfad72324b2bb2e43c98                           0.0s 
 => [internal] load build context                                                                                                               0.0s 
 => => transferring context: 6.11kB                                                                                                             0.0s 
 => CACHED [2/9] RUN apt update                                                                                                                 0.0s 
 => CACHED [3/9] RUN apt  install -yy gcc g++ cmake                                                                                             0.0s 
 => [4/9] COPY . /solver_application                                                                                                            0.1s 
 => [5/9] WORKDIR /solver_application                                                                                                           0.0s 
 => [6/9] RUN cmake -H. -B_build -DDCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=_install                                                    2.0s 
 => [7/9] RUN cmake --build _build                                                                                                              1.7s
 => [8/9] RUN cmake --build _build --target install                                                                                             0.6s 
 => [9/9] WORKDIR /solver_application/_build/                                                                                                   0.0s 
 => exporting to image                                                                                                                          4.7s 
 => => exporting layers                                                                                                                         4.7s 
 => => writing image sha256:6132c1e22bc18d25c0d3065cba25b030c5195d0d7293aa0b43317fa42c50a675                                                    0.0s 
 => => naming to docker.io/library/logger 
```

## Links

- [Book](https://www.dockerbook.com)
- [Instructions](https://docs.docker.com/engine/reference/builder/)

```
Copyright (c) 2015-2021 The ISC Authors
```
