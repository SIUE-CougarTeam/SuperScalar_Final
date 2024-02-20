#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <iomanip>
using namespace std;

int main()
{
        char buffer[4];
        int i;
        char * iPtr;
        iPtr = (char*)(void*) &i;

        int FD = open("test1.bin", O_RDONLY);

        int amt = 4;
        while( amt != 0 )
        {
                amt = read(FD, buffer, 4);
                if( amt == 4)
                {
                        iPtr[0] = buffer[3];
                        iPtr[1] = buffer[2];
                        iPtr[2] = buffer[1];
                        iPtr[3] = buffer[0];
                        cout << "i = " <<hex<< i << endl;
                        cout << "op code: " << dec << (((unsigned int)i)>>26) << endl;
                        cout << "rs bits: " << ((((unsigned int)i)<<6)>>27) << endl;
                }
        }







}
