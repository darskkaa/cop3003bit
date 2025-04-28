#include "adil_quantum.h"

int main () {
    char originalBits [152]; // array to hold the files orignal sequence, uses the header for size
    std::ifstream binSeqfile("/Users/adilzaben/Downloads/binSeq.txt"); // read file
    for(int i = 0; i < 152; i++){  //loop through the file 152 times
        binSeqfile >> originalBits[i];    //write a 1 or 0 from the file to the array
    }  binSeqfile.close();   //close the file
    
    //flip the pairs
    char flipBitAlpha[128]//first alpha for the pair
    char comma;
    char flipBitBeta[128];      //second bit , beta in the pair
    std::ifstream flipFile ("/Users/adilzaben/Downloads/binSeq.txt"); // read file
    for(int i = 0; i < 128; i++)  {  //loop thriugh the lines of the file
        flipFile >> flipBitAlpha[i] >> comma >> flipBitBeta[i];
    
    flipFile.close ();
    
    char firstEncryption [304]; // when each bit is * 2, so 304;
    
    for (int bit = 0; bit < 152; bit++){ //use the int bit to hold the bit posiio in the original sequence
        int randomIndex = std::rand() % 128;//out of 128 pairs choose  a random one
        if(originalBits[bit]] == '0' {      //if the original bit sequence is a 0, keep
           firstEncryption[ 2 * bit] = flipBitAlpha[randomIndex]; //use the randindex to get val 1-128 which dictates the colomn  select 
           firstEncryption[ 2 * bit] = flipBitBeta[randomIndex]; //use the randindex to get val 1-128 which dictates the colomn  select 


            }
    else {
            }
           firstEncryption[ 2 * bit] = flipBeta[randomIndex]; // if the bit is '1', flip the pairs so beta goes first
           firstEncryption[ 2 * bit] = flipAlpha[randomIndex]; //alpha goes seco
}

    
    std::cout << "First Encryption Mod 128" << std::endl;
        std::bitset<8> byte(std::string(firstEncryption);
        std::cout << byte.to_ulong();
            std::cout << ".";
        }

  
    char secondEncryption [304]; // when each bit is * 2, so 304;
    
    for (int bit = 0; bit < 152; bit++){ //use the int bit to hold the bit posiio in the original sequence
        int randomIndex = std::rand() % 64;//out of 64 pairs choose  a random one
        if(originalBits[bit]] == '0' {      //if the original bit sequence is a 0, keep
           secondEncryption[ 2 * bit] = flipBitAlpha[randomIndex]; //use the randindex to get val 1-128 which dictates the colomn  select 
           secondEncryption[ 2 * bit] = flipBitBeta[randomIndex]; //use the randindex to get val 1-128 which dictates the colomn  select 


            }
    else {
            }
           secondEncryption[ 2 * bit] = flipBeta[randomIndex]; // if the bit is '1', flip the pairs so beta goes first
           secondEncryption[ 2 * bit] = flipAlpha[randomIndex]; //alpha goes seco
}

    
    std::cout << "Second Encryption Mod 64" << std::endl;
        std::bitset<8> byte(std::string(secondEncryption, 8);
        std::cout << byte.to_ulong();
            std::cout << ".";
        }



