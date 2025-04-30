#include "ADIL_QUANTUM.h"


int main () {
        srand(time(0)); // initialize the random number generator
    char originalBits [152]; // array to hold the files orignal binary sequence
    std::ifstream binSeqfile("binSeq.txt"); // open binary sequence file
    if(!binSeqfile){  //check if the file was opened succesfully
        std::cout<<"binSeq.txt not found"<<std::endl;
        return 1; //exit if missing
        
    }
    

    for(int i = 0; i < 152; i++){  
        binSeqfile >> originalBits[i];    //read the 152 chars, 0 or 1 into the originalBits array
        
    }  binSeqfile.close();   //close the file 
    
    //setup for reading flip bit pairs from flip file
    char flipBitAlpha[128]; // alpha  values from the flip pair file
    char comma;  //ensure the file is read properly, separator for the comma
    char flipBitBeta[128];      //second bit , beta in the pair
    std::ifstream flipFile ("flip.txt"); // open the flip file
    if(!flipFile){      //ensure the file was opened successfully
        std::cout<<"flip.txt not found"<<std::endl;
        return 1;
        
    }
    
  



    for(int i = 0; i < 128; i++)  {  //read the 128 alpha beta pairs from the flip file
        flipFile >> flipBitAlpha[i] >> comma >> flipBitBeta[i]; //read the pairs
    }
    flipFile.close (); 
    
    std::string firstEncryption = "";  //  holds the 304 bit string

    //starts the first encrption process using mod 128, loop through original bits
    //encrypts using a random flip pair from mod 128.
    for (int bit = 0; bit < 152; bit++) { 
        int randomIndex = std::rand() % 128;// choose a random number, index, from 0-127

        if(originalBits[bit] == '0')  {   
            
           // if the bit is 0, then append alpha then beta from the random selected pair
            firstEncryption += flipBitAlpha[randomIndex];  
            firstEncryption += flipBitBeta[randomIndex]; 
                
        }
        else { 
            // if the original bit was not 0 its 1, append beta then alpha, aka flipping
            firstEncryption += flipBitBeta[randomIndex];
            firstEncryption += flipBitAlpha[randomIndex];     
            
            
        }
        
        
    }
    
    //convert 304 bit encrypted string into decimal values, using 8 bit sections 
    std::cout << "First Encryption Mod 128: " << std::endl;
    for (int i= 0; i < 304; i+= 8){ 

        // at index i, take an 8 bit substring from the encrypted sequence for conversion
        std::string eightByteString = firstEncryption.substr(i, 8); 

        //makes an 8 bit binary object, byte, from the binary substring, using bitset
        std::bitset<8> byte(eightByteString); 

        //convert the binary to decimal and prints it 
        std::cout << byte.to_ulong();  
        
        std::cout << "."; //print a decimal to separate each decimal number 
    } std::cout << std::endl;
    
    
    std::cout << std::endl;

    
    std::string secondEncryption = "";  // holds the 304 bit string

    //starts the second encryption process using mod 64, loop through original bits
    //encrypts using a random flip pair from mod 64.
    for (int bit = 0; bit < 152; bit++) { 
        int randomIndex = std::rand() % 64;// choose a random number, index, from 0-63

        if(originalBits[bit] == '0')  {   
            
           // if the bit is 0, then append alpha then beta from the random selected pair
            secondEncryption += flipBitAlpha[randomIndex];  
            secondEncryption += flipBitBeta[randomIndex]; 
                
        }
        else { 
            // if the original bit was not 0 its 1, append beta then alpha, aka flipping
            secondEncryption += flipBitBeta[randomIndex];
            secondEncryption += flipBitAlpha[randomIndex];     
            
            
        }
        
        
    }
    
    //convert 304 bit encrypted string into decimal values, using 8 bit sections 
    std::cout << "Second Encryption Mod 64: " << std::endl;
    for (int i= 0; i < 304; i+= 8){ 

        // at index i, take an 8 bit substring from the encrypted sequence for conversion
        std::string eightByteString = secondEncryption.substr(i, 8); 

        //makes an 8 bit binary object, byte, from the binary substring, using bitset
        std::bitset<8> byte(eightByteString); 

        //convert the binary to decimal and prints it 
        std::cout << byte.to_ulong();  
        
        std::cout << "."; //print a decimal to seperate each decimal number 
    } std::cout << std::endl;
    
    
    std::cout << std::endl;
    

    return 0;
}
