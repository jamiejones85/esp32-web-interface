/*
 * This file is part of the esp32 web interface
 *
 * Copyright (C) 2018 Johannes Huebner <dev@johanneshuebner.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#ifndef OI_CAN_H
#define OI_CAN_H
#include <WiFiClient.h>

namespace OICan {
enum SetResult { Ok, UnknownIndex, ValueOutOfRange, CommError };
enum BaudRate { Baud125k, Baud250k, Baud500k };

void Init(uint8_t nodeId, BaudRate baud);
void Loop();
bool SendJson(WiFiClient c);
void SendCanMapping(WiFiClient c);
void DeleteParams();
SetResult AddCanMapping(String json);
SetResult RemoveCanMapping(String json);
SetResult SetValue(String name, double value);
double GetValue(String name);
bool SaveToFlash();
String StreamValues(String names, int samples);
int StartUpdate(String fileName);
int GetCurrentUpdatePage();
int GetNodeId();
BaudRate GetBaudRate();

}
#endif
