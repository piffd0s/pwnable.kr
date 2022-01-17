#include <stdio.h>
#include <string.h>
unsigned long hashcode = 0x21DD09EC; //our password needs to match this
unsigned long check_password(const char* p){ //takes a char pointer p returns an unsigned long
        int* ip = (int*)p; //cast car * p to an integer pointer
        int i;
        int res=0;
        for(i=0; i<5; i++){
                res += ip[i]; //*(ip + i) 
                //here the code iterates over our input and takes each 4 bytes of input and turns it into a hex value
                //this is how we get from 20 bytes to 8 byte hex value
                //if we do the reverse we could get the input value to 21DD09EC?
                //  
        }
        return res;
}

int main(int argc, char* argv[]){
        if(argc<2){
                printf("usage : %s [passcode]\n", argv[0]);
                return 0;
        }
        if(strlen(argv[1]) != 20){
                printf("passcode length should be 20 bytes\n"); //20 byte (character input)
                return 0;
        }

        if(hashcode == check_password( argv[1] )){
                system("/bin/cat flag");
                return 0;
        }
        else
                printf("wrong passcode.\n");
                printf(hashcode)
        return 0;
}

//maths

//21DD 09EC = 568134124
//10101010 = 269488144
//11CCF9DC = 298,645,980
//somehow i got my math wrong, the correct input would be
//./col "`python -c "print '\x04' * 16 + '\xdc\xf9\xcc\x11'"`"