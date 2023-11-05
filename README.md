# Project-3: Parking Lot Simulation

![](https://img.shields.io/badge/VG151-p3-green.svg)
![](https://img.shields.io/badge/Lang-cpp17-blue.svg)
![](https://img.shields.io/badge/Plot-OpenGL-cyan.svg)
![](https://img.shields.io/badge/Simulation-ParkingLot-red.svg)
![](https://img.shields.io/badge/Author-pgroup_07-yellow.svg)
![](https://img.shields.io/badge/Drone-pass-brightgreen.svg)

## Author: pgroup-07

| Author         | Student id                                                  |
|----------------|-------------------------------------------------------------|
| GOR TADEVOSYAN | (https://focs.ji.sjtu.edu.cn/git/gortadevosyan)    |
| Hongzheng Hu   | (https://focs.ji.sjtu.edu.cn/git/huhongzheng) |
| Jiayue Huang   | (https://focs.ji.sjtu.edu.cn/git/huangjiayue) |
| Zhewen He      | (https://focs.ji.sjtu.edu.cn/git/hezhewen)    |

## Description

### Introduction

This project is about a parking lot simulation program, including `pms` and `ipa` mode.

* pms  
  pms provide a general parking lot simulation in CLI mode, including
  slots & groups simulation, finding empty slots and printing ticket
* ipa  
  ipa provide an animation version of pms based on OpenGL

### Running

* Windows

```shell

```

* Linux

```shell
git clone ssh://git@focs.ji.sjtu.edu.cn:2222/ENGR151-22/pgroup-07.git -b 522370910184
cd pgroup-07
mkdir build && cd build
cmake ..
make 
./ipa/ipa
```

**Cross-platform function is not finished yet**

### Output

Example:

## MileStone

### MileStone-1

1. basic classes structure
2. basic pms mode for general parking lot
3. Vec.h for project math tools
4. Utils.h/CommonValue.h/Logger.h for project utils

### MileStone-2

1. reorganization for ipa/pms
2. finish group/slot manager for ipa
3. finish main plotting for moving group to slot
4. finish figure(Figure,ColoredFigure,Circle,Rectangle,Quad)
5. finish group(Car,Teleported)

### MileStone-3

### Bonus-Part

## Bugs Report

## Contributor & Contribution
TBA


