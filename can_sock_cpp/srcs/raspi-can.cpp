#include "../inc/raspi-can.h"
#include "../inc/utils.h"

int InitSocket(const char *ifname)
{
	int sock_fd = socket(PF_CAN, SOCK_RAW, CAN_RAW);
	if (sock_fd < 0)
		return PrintErrorText("Failed to socket create", sock_fd);
	PrintSuccessText("Success to socket create");

	struct ifreq ifr;
	strcpy(ifr.ifr_name, ifname);
	int ret = ioctl(sock_fd, SIOCGIFINDEX, &ifr);
	if (ret < 0)
		return PrintErrorText("Failed to get CAN interface index", ret);
	printf("%sSuccess to get CAN interface index : %d%s\n", 
					COLOR_BGREEN, ret, COLOR_RESET);

	struct sockaddr_can addr;
	addr.can_family = AF_CAN;
	addr.can_ifindex = ifr.ifr_ifindex;
	ret = bind(sock_fd, (struct sockaddr *)&addr, sizeof(addr));
	if (ret < 0)
		PrintErrorText("Failed to socket bind", ret);
	PrintSuccessText("Success to socket bind");
	
	return sock_fd;
}


int main()
{
	int can_fd = InitSocket("can0");
	if (can_fd < 0)
		return can_fd;
	
	struct can_frame frame;
	while (1)
	{
		int rd_byte = read(can_fd, &frame, sizeof(frame));
		if (rd_byte < 0)
			return PrintErrorText("Failed to recieve CAN frame", rd_byte);
		else if (rd_byte < (int)sizeof(struct can_frame))
			return PrintErrorText("Incomplete CAN frame is received", rd_byte, rd_byte);
		else if (frame.can_dlc > CAN_FRAME_MAX_LEN)
			return PrintErrorText("Invalid dlc", -1, frame.can_dlc);

		
		printf("0x%03X [%d] ",frame.can_id, frame.can_dlc);

		for (int i = 0; i < frame.can_dlc; i++)
			printf("%02X ",frame.data[i]);
		printf("%f\n", static_cast<float>(frame.data[0]));
		printf("\n");
		
	}

	return 0;
}