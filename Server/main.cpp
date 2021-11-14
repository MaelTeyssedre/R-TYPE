/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** main
*/

#include <iostream>
#include "Packet.hpp"

int main()
{
  Packet packet;
  std::vector<uint8_t> data;
  char opcode = 9;

  for (int i = 0; i < 20; i++) {
    data.push_back((uint8_t)opcode);
    //opcode++;
  }

  packet.pack(data);
  return (0);
}