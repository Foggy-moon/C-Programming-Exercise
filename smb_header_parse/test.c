#include <stdio.h>
#include <memory.h>

typedef struct {
	int protocolId;
	short length;
	short creditCharge;
	short channelSeq;
	short reserved;
	short cmd;
	short creditsReq;
	int flags;
}SmbHeader;

int main()
{
	FILE* fp;
	char* pkgFile = "D:/C-Programming-Exercise/smb_header_parse/smb_create_req.bat";
	int res = fopen_s(&fp,pkgFile,"rb");
	if (res != 0) {
		printf("wireshark file opened failed;");
	}
	else {
		printf("wireshark file opened succeed.");
	}
	SmbHeader* obj = (SmbHeader*)malloc(sizeof(SmbHeader));

	fread();
	getchar();
}