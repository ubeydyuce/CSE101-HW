#include <stdlib.h> 
#include <stdint.h>   /* Standard types */
#include <string.h>   /* String function definitions */
#include <unistd.h>   /* UNIX standard function definitions */
#include <fcntl.h>    /* File control definitions */
#include <errno.h>    /* Error number definitions */
#include <termios.h>  /* POSIX terminal control definitions */
#include <sys/ioctl.h>
#include <getopt.h>
#include <stdio.h>   /* Standard input/output definitions */
#include <string.h>  /* String function definitions */
#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */
#include <time.h>
#include <sys/types.h>

int main(){
	printf("Hello World\n");	
	
	// Method 1
	//Open communication with arduino	
	int portName = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY);
	
	struct termios options;
	tcgetattr(portName, &options);
	cfsetispeed(&options, B9600);
	cfsetospeed(&options, B9600);
	options.c_cflag |= (CLOCAL | CREAD);
	tcsetattr(portName, TCSANOW, &options);
		
	options.c_cflag &= ~CSIZE; /* Mask the character size bits */
	options.c_cflag |= CS8;    /* Select 8 data bits */
	//No parity
	options.c_cflag &= ~PARENB;
	options.c_cflag &= ~CSTOPB;
	
	
	char num[5] ;
	
	while(1){
		printf("## WELCOME TO GTU ARDUINO LAB        ##\n");
		printf("## STUDENT NAME : UBEYDULLAH YÜCE       ##\n");
		printf("## PLEASE SELECT FROM THE FOLLOWING       ##\n");
		printf("## MENU :       ##\n");
		printf("(1) TURN ON LED ON ARDUINO\n");
		printf("(2) TURN ON LED OFF ARDUINO\n");
		printf("(3) FLASH ARDUINO LED 3 TIMES\n");
		printf("(4) SEND A NUMERAL TO ARDUINO TO COMPUTE SQUARE BY ARDUINO\n");
		printf("(5) Button press counter (bonus item)\n");
		printf("(0) Exit\n");
		int input = 0 ;
		
		scanf("%d",&input);
		if(input == 1){
			num[0] = '1';
			write(portName, num, 1);
		}
		else if(input==0){
			num[0]='0';
			write(portName, num, 1);
			break;
		}
		else if(input == 2){
			num[0] = '2';
			write(portName, num, 1);
		}
		else if(input == 3){
			num[0] = '3';
			write(portName, num, 1);
		}
		else if(input==4){
			char number[5];
			num[0]='4';
			write(portName, num, 1);
			number[0] = '8';

			getchar();

			scanf("%s",number);
			
			write(portName,number,1);
			
		}


	}

	close(portName);

	return 0;
}