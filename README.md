<h1 align="center">
  <br>
  <a href="http://www.github.com/ArthurCrespy"><img src="https://42.fr/wp-content/uploads/2021/05/42-Final-sigle-seul.svg" alt="42" width="200"></a>
  <br><br>
  minitalk
  <br>
</h1>

<h3 align="center">The purpose of this project is to code a small data exchange program using UNIX signals.</h3>

<h4 align="center">Create a communication program in the form of a client and a server.</a></h4>

<p align="center">
    <a href="https://github.com/ArthurCrespy/minitalk/search?l=c"> <img alt="Language: C" src="https://img.shields.io/badge/language-C-orange"></a>
        <a href="https://github.com/ArthurCrespy/minitalk"> <img alt="Lines of code" src="https://img.shields.io/tokei/lines/github/ArthurCrespy/minitalk"></a>
    <a href="https://github.com/ArthurCrespy/minitalk/commits"> <img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/ArthurCrespy/minitalk?color=yellow"></a>
    <a href="https://github.com/ArthurCrespy/minitalk/watchers"> <img alt="GitHub watchers" src="https://img.shields.io/github/watchers/ArthurCrespy/minitalk?color=ff69b4"></a>
    <a href="https://projects.intra.42.fr/42cursus-minitalk/acrespy"> <img alt="Result: 125/100" src="https://img.shields.io/badge/result-125/100-brightgreen"></a>

</p>

<p align="center">
  <a href="#introduction">Introduction</a> •
  <a href="#how-to-use">How To Use</a> •
  <a href="#description">Description</a> •
  <a href="#about-42-cursus">About 42 Cursus</a> •
  <a href="#you-may-also-like">Related</a> •
  <a href="#license">License</a>
</p>

## Introduction



## How To Use

To clone and run this project, you'll need [Git](https://git-scm.com) and [Clang](https://clang.llvm.org/) installed on your computer. From your command line:

```bash
# Clone this repository via HTTPS
$ git clone https://github.com/ArthurCrespy/minitalk
# OR clone this repository via SSH
$ git clone git@github.com:ArthurCrespy/minitalk.git

# Go into the repository
$ cd minitalk

# Run the Makefile
$ make

# Run the server
$ ./server

# Run the client
$ ./client [PID] [MESSAGE]
```

> **Note**
> The Makefile will compile using ```clang``` with flags ```-Wall -Wextra -Werror``` and will be named ```server``` & ```client```. ```server``` should be running when ```client``` is executed.

### Makefile

- ```make``` or ```make all``` : Compile the program.
- ```make clean``` : Delete all objects files.
- ```make fclean``` : Delete all objects files and the instances.
- ```make re``` : Delete all files (except sources, of course) and recompile it.

## Description

This project is about creating a communication program in the form of a client and a server. The server must be able to display the string received as a parameter. The client must be able to send the string passed as a parameter to the server.
The server must be able to display the string received as a parameter. The client must be able to send the string passed as a parameter to the server.
The client and the server must be able to communicate using only the SIGUSR1 and SIGUSR2 signals.


## About 42 Cursus

This project is the first of the Cursus. It allows you to remember the basics of the C language seen in the Piscine. It's the only project of Core00 and unlocks Core01. The library will be reused in future projects

## You may also like...

- [so_long](https://github.com/ArthurCrespy/so_long) - And thanks for all the fish!
- [push_swap](https://github.com/ArthurCrespy/push_swap) - Because Swap_push isn’t as natural

## License

For now, all rights are reserved.

---
<p align="center">
    <a href="https://github.com/ArthurCrespy"> <img alt="Made by ArthurCrespy" src="https://img.shields.io/badge/made%20by-ArthurCrespy-blue"></a>
    <a href="https://42.fr"><img alt="42 Website" src="https://img.shields.io/badge/website-42.fr-blue"></a>
    <br>
    Github <a href="https://github.com/ArthurCrespy" target="_blank">@Thur'</a> |
    LinkedIn<a href="https://fr.linkedin.com/in/crespyarthur" target="_blank"> @Arthur Crespy</a> |
    Instagram<a href="https://instagram.com/arthurcrespy" target="_blank"> @crespyarthur</a> 
</p>
