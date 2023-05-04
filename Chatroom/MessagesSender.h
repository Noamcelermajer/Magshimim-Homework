#pragma once
#include <iostream>
#include <vector>
#include <time.h>
#include <string>
#include <thread>
#include <queue>
#include <fstream>
#include <mutex>

void MessagerMain();
void  BroadcastMessage();
int signin();
int signout();
void connectedUser();
void getFromFiles();