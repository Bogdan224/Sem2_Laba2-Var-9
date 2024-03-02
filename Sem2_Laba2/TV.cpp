#include "TV.h"

TV* Init(const char model[20], int displaySize, bool haveWIFI)
{
	TV* tv = (TV*)malloc(sizeof(TV));
	strncpy(tv->_model, model, 20);
	tv->_displaySize = displaySize;
	tv->_haveWIFI = haveWIFI;
	return tv;
}
void PrintTV(TV* tv)
{
	printf("Model: %s\nDisplay size: %d\n", tv->_model, tv->_displaySize);
	if (tv->_haveWIFI) {
		printf("Have WIFI: Yes\n");
	}
	else {
		printf("Have WIFI: No\n");
	}
}
bool Equals(TV* tv1, TV* tv2)
{
	if (strcmp(tv1->_model, tv2->_model) != 0)
	{
		return false;
	}
	else if (tv1->_displaySize != tv2->_displaySize)
	{
		return false;
	}
	else if (tv1->_haveWIFI != tv2->_haveWIFI)
	{
		return false;
	}
	return true;
}
bool Less(TV* tv1, TV* tv2)
{
	if (tv1->_displaySize < tv2->_displaySize) {
		return true;
	}
	else {
		return false;
	}
}
