/*Write a C/C++ POSIX compliant program that prints the POSIX defined configuration options
   supported on any given system using feature test macros.
*/
#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L
#include "iostream"
#include<unistd.h>
using namespace std;
int main()
{
        #ifdef _POSIX_JOB_CONTROL
                cout<<"System supports POSIX job control:"<<_POSIX_JOB_CONTROL<<endl;
        #else
                cout<<"System  does not support POSIX job control"<<endl;
        #endif
        #ifdef _POSIX_SAVED_IDS
                cout<<"System supports saved set UID and GID:"<<_POSIX_SAVED_IDS<<endl;
        #else
                cout<<"System does not support saved set GID and UID"<<endl;
        #endif
        #ifdef _POSIX_CHOWN_RESTRICTED
                cout<<"Chown restricted option is :"<<_POSIX_CHOWN_RESTRICTED<<endl;
        #else
                cout<<"Chown Restricted not defined"<<endl;
        #endif
        #ifdef _POSIX_NO_TRUNC
                cout<<"Truncation option is :"<<_POSIX_NO_TRUNC<<endl;
        #else
                cout<<"Truncation Option not defined"<<endl;
        #endif
        #ifdef _POSIX_VDISABLE
                cout<<"disable char for terminal files"<<_POSIX_VDISABLE<<endl;
        #else
                cout<<"char for terminal device files will not be diasbled"<<endl;
        #endif
        return 0;
}
