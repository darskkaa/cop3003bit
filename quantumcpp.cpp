#include "ADIL_QUANTUM.h"

int main () {
    char originalBits [152]; // array to hold the files orignal sequence
    std::ifstream binSeqfile("binSeq.txt"); // read file
    if(!binSeqfile){
        std::cout<<"binSeq.txt not found"<<std::endl;
        return 1;
        
    }
    

    for(int i = 0; i < 152; i++){  //loop through the file 152 times
        binSeqfile >> originalBits[i];    //write a 1 or 0 from the file to the array
        
        
    }  binSeqfile.close();   //close the file
    
    //flip the pairs
    char flipBitAlpha[128]; //first alpha for the pair
    char comma;  //ensure the file is read properly
    char flipBitBeta[128];      //second bit , beta in the pair
    std::ifstream flipFile ("flip.txt"); // read file
    if(!flipFile){
        std::cout<<"flip.txt not found"<<std::endl;
        return 1;
        
    }
    
  



    for(int i = 0; i < 128; i++)  {  //loop thriugh the flip pairs
        flipFile >> flipBitAlpha[i] >> comma >> flipBitBeta[i]; //read alpha, comma, then beta
    }
    flipFile.close ();
    
    std::string firstEncryption = "";  //an empty string for the concantation
    
    
    for (int bit = 0; bit < 152; bit++) { //use the int bit to hold the bit posiio in the original sequence
        int randomIndex = std::rand() % 128;//out of 128 pairs choose  a random one
        if(originalBits[bit] == '0')  {   //if the original bit sequence is a 0, keep the curent alpha beta
            //appends the alpha bit from the random pair slected pir 1-28 from modulo to the encyrpted string
            firstEncryption += flipBitAlpha[randomIndex]; //use the randindex to get val 1-128 which dictates the row  select from flip -1
            //appends the beta bit from the random pair slected pir 1-128 from modulo to the encyrpted string
            firstEncryption += flipBitBeta[randomIndex]; //use the randindex to get val 1-128 which dictates the row  select from flip-1
            
            
            
        }
        else { // if the original bit was not 0 its 1
            //appends the alpha bit from the random pair slected pir 1-128 from modulo to the encyrpted string
            firstEncryption += flipBitBeta[randomIndex]; //use the randindex to get val 1-128 which dictates the row  select from flip -1
            //appends the beta bit from the random pair slected pir 1-128 from modulo to the encyrpted string
            firstEncryption += flipBitAlpha[randomIndex]; //use the randindex to get val 1-128 which dictates the row  select from flip-1
            
            
            
            
        }
        
        
    }
    
    
    std::cout << "First Encryption Mod 128: " << std::endl;
    for (int i= 0; i < 304; i+= 8){ //loop through the 304 long string, into 8 bit sections
        std::string eight_byte_to_strings = firstEncryption.substr(i, 8); // at index i, start getting 8 byte substrings.
        
        std::bitset<8> byte(eight_byte_to_strings);  // use that 8 bit string to binary
        std::cout << byte.to_ulong();  //print the actaul decimal value of the binary using the u-long bitset operand
        std::cout << "."; //seperate by dot
    } std::cout << std::endl;
    
    
    
    std::cout << std::endl;
    std::string secondEncryption = "";  //an empty string for the concantation
    
    
    for (int bit = 0; bit < 152; bit++) { //use the int bit to hold the bit posiio in the original sequence
        int randomIndex = std::rand() % 64;//out of 64 pairs choose  a random one
        if(originalBits[bit] == '0')  {   //if the original bit sequence is a 0, keep the curent alpha beta
            //appends the alpha bit from the random pair slected pir 1-28 from modulo to the encyrpted string
            secondEncryption += flipBitAlpha[randomIndex]; //use the randindex to get val 1-128 which dictates the row  select from flip -1
            //appends the beta bit from the random pair slected pir 1-128 from modulo to the encyrpted string
            secondEncryption += flipBitBeta[randomIndex]; //use the randindex to get val 1-128 which dictates the row  select from flip-1
            
            
            
        }
        else { // if the original bit was not 0 its 1
            //appends the alpha bit from the random pair slected pir 1-128 from modulo to the encyrpted string
            secondEncryption += flipBitBeta[randomIndex]; //use the randindex to get val 1-128 which dictates the row  select from flip -1
            //appends the beta bit from the random pair slected pir 1-128 from modulo to the encyrpted string
            secondEncryption += flipBitAlpha[randomIndex]; //use the randindex to get val 1-128 which dictates the row  select from flip-1
            
            
            
            
        }
        
        
    }
    
    std::cout << "Second Encryption Mod 64: " << std::endl;
    for (int i= 0; i < 304; i+= 8){ //loop through the 304 long string, into 8 bit sections
        std::string eight_byte_to_strings = secondEncryption.substr(i, 8); // at index i, start getting 8 char substrings. each as 8 bit blocks
        std::bitset<8> byte(eight_byte_to_strings);  // use that 8 bit string to binary
        std::cout << byte.to_ulong();  //print the actaul decimal value of the binary using the u-long bitset operand
            std::cout << "."; //seperate by dot
        
    }
    std::cout << std::endl;
    

    return 0;
}
