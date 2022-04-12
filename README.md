
# Archived: Use socat instead

# cluon-udp-sniffer

Copyright 2021 RISE Research Institute of Sweden - Maritime Operations. Licensed under the Apache License Version 2.0. For details, please contact Fredrik Olsson (fredrik.x.olsson(at)ri.se).

A [libcluon](https://github.com/chrberger/libcluon)-based command-line tool for listening into all kinds of different UDP streams. Useful as a debugging tool.

## How do I get it?
Build it with CMake and use the built binary as a regular command line executable.

## Example usage

```bash
./cluon-udp-sniffer -a 239.192.0.2 -p 600002 -i 172.31.16.101
```

### Development setup
This repo contains some configuration files (in the `.vscode`-folder) for getting started easy on the following setup:
* Ubuntu 20.04 (WSL2 is fine)
* GCC 9
* python 3
* VSCode as IDE, using the following extensions:
  - C/C++ (ms-vscode.cpptools)
  - C/C++ Extension Pack (ms-vscode.cpptools-extension-pack)
  - CMake Tools (ms-vscode.cmake-tools)
  - Python (ms-python.python)

Do the following steps to get started:
* Clone repo
* Create a python virtual environment (`python3 -m venv venv`) in the root of the repo.
* Open vscode in the repo root (`code .`)

The provided configuration is very lightweight and should be easily adaptable to other enviroments/setups.

