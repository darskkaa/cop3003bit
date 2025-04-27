#include <fstream>
#include <bitset>
#include <iostream>
#include <string>
#include "math.h"


int main () {
  char originalBits [ 152 ]; // array to hold the files orignal sequence
  std::ifstream binSeqfile("/Users/adilzaben/Downloads/binSeq.txt"); // read file
  for(int i = 0; i < 152; i++){  //loop through the file 152 times
      binSeqfile >> originalBits[i[];    //write a 1 or 0 from the file to the array
  }  binSeqfile.close();   //close the file
                            
//flip the pairs
char flipBitAlpha[128];        //first alpha for the pair
  char flipBitBeta[128];      //second bit , beta in the pair
    std::ifstream flipFile ("/Users/adilzaben/Downloads/binSeq.txt"); // read file
    for(int i = 0; i < 128; i++)  {  //loop thriugh the lines of the file
      flipFile >> flipBitAlpha [i];      //read alpha first, then beta
        flipFile >> flipBitBeta [i];
    }
  flipFile.close (); 


std::srand();
  char firstEncryption [304]; // when each bit is * 2, so 304;

  for (int bit = 0; bit < 152; bit++){ //use the int bit to hold the bit posiio in the original sequence
    int randomIndex = rand() % 128;   //out of 128 pairs choose  a random one
    firstEncryption [ 2 * bit] = flipBitAlpha [randomIndex]; //use the alpha from the random pair, and puts into the encryoted array
    firstEncryption [ 2 * bit] = flipBitBeta [randomIndex]; //use the alpha from the random pair, and puts into the encryoted array
}

std::cout<<"First Encryption Mod 128" << std::endl;
    std::bitset<8> byte( std::string(firstEncryption)); // load 8 chars
  byte.flip();
   byte.to_ulong();
  std::cout<<"\n";
  
}




std::srand();
  char secondEncryption [304]; // when each bit is * 2, so 304;

  for (int bit = 0; bit < 152; bit++) //use the int bit to hold the bit posiio in the original sequence
    int randomIndex = rand() % 64   //out of 128 pairs choose  a random one
    secondEncryption [ 2 * bit] = flipBitAlpha [randomIndex]; //use the alpha from the random pair, and puts into the encryoted array
    secondEncryption [ 2 * bit] = flipBitBeta [randomIndex]; //use the alpha from the random pair, and puts into the encryoted array

std::srand();
  char secondEncryption [304]; // when each bit is * 2, so 304;

  for (int bit = 0; bit < 152; bit++){ //use the int bit to hold the bit posiio in the original sequence
    int randomIndex = rand() % 128;   //out of 128 pairs choose  a random one
    secondEncryption [ 2 * bit] = flipBitAlpha [randomIndex]; //use the alpha from the random pair, and puts into the encryoted array
    secondEncryption [ 2 * bit] = flipBitBeta [randomIndex]; //use the alpha from the random pair, and puts into the encryoted array
}

std::cout<<"Second Encryption Mod 128" << std::endl;
    std::bitset<8> byte( std::string(secondEncryption)); // load 8 chars
  byte.flip();
   byte.to_ulong();
  std::cout<<"\n";
return 0; 
  
}



