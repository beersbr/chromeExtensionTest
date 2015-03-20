
#include <iostream>
#include <cstdlib>
#include <unistd.h>

int main(int argc, char *argv[])
{
	std::string app_path = "open";

	std::string str = "{ \"text\": \"hello world!\"}";
	unsigned int str_sz = str.length();

	std::cout.write((char *)&str_sz, 4);
	std::cout.write(str.c_str(), str_sz);

	// if(execl("/usr/bin/open", "open", "/Applications/App Store.app/", NULL) < 0)
	// {
	// 	std::cout << "ERROR: " << errno << std::endl;
	// 	return 1;
	// }

	return 0;
}