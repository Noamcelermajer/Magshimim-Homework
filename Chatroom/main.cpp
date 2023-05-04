#include "MessagesSender.h"
int main()
{
	std::thread g(getFromFiles);
	std::thread b(BroadcastMessage);
	g.detach();
	b.detach();
	MessagerMain();
	system("pause");
}