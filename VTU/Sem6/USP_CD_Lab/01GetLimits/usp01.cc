#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L

#include "iostream"
#include <unistd.h>
using namespace std;

int main()
{
	cout << "No of clock ticks: " << sysconf(_SC_CLK_TCK) << endl;
	cout << "Maximum no of child processes: " << sysconf(_SC_CHILD_MAX) << endl;
	cout << "Maximum path length: " << pathconf("/", _PC_PATH_MAX) << endl;
	cout << "Maximum characters in a file name: " << pathconf("/", _PC_NAME_MAX) << endl;
	cout << "Maximum no of open files: " << sysconf(_SC_OPEN_MAX) << endl;
	return 0;
}
