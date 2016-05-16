//	ÇUKUROVA UNIVERSITY
//	COMPUTER ENGINEERING
//	TOLGA AKKAPULU

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include "graphics.h"

int gcd(int number1, int number2)
{
	if (number1<number2)
	{
		int swap = number1;
		number1 = number2;
		number2 = swap;
	}
	while (number2 != 0)
	{
		int remainder = number1%number2;
		number1 = number2;
		number2 = remainder;
	}
	return number1;
}



int crypte(long m, long n, long e)
{
	int result = 1;
	while (e>0)
	{
		if (e % 2 == 1)
		{
			result = (result*m) % n;
		}
		e = e / 2;
		m = (m*m) % n;
	}

	return result;
}

void find_d(long a, long b, long *x, long *y, int *d)
{
	long q, r, x1, x2, y1, y2;
	if (b == 0)
	{
		*d = a, *x = 1, *y = 0;
		return;
	}
	x2 = 1, x1 = 0, y2 = 0, y1 = 1;

	while (b>0)
	{
		q = a / b, r = a - q * b;
		*x = x2 - q*x1, *y = y2 - q*y1;
		a = b, b = r;
		x2 = x1, x1 = *x, y2 = y1, y1 = *y;
	}
	*d = a, *x = x2, *y = y2;
}


int main()
{
	long x, y;
	int prime[10] = { 101, 103, 107, 109, 113, 127, 131, 137, 139, 149 };
	int prime_e[10] = { 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };
	int p, q, e, d, n, totient, encrypting, decrypting;
	int message;
	char text[80];

	initwindow(1316, 600, "RSA ALGORTIHM");
	setcolor(GREEN);
	rectangle(5,5,1300,585);

	srand(time(NULL));
	p = prime[rand() % 10];
	q = prime[rand() % 10];
	while (p == q)
	{
		q = prime[rand() % 10];
	}

	setcolor(RED);
	settextstyle(6, HORIZ_DIR, 3);
	outtextxy(10,10,"*****************************");
	setcolor(GREEN);
	outtextxy(514, 10, "RSA ALGORITHM");
	setcolor(RED);
	outtextxy(800, 10, "*****************************");
	setcolor(RED);
	outtextxy(10, 30, "---------------------------------------------------------------------------------------------------------------------");


	printf("***************************\n");
	printf("*******RSA ALGORITHM*******\n");
	printf("***************************\n");
	printf("p  :  %d    q\t:  %d\n", p, q);
	printf("***************************");
	
	outtextxy(400, 70, "p  :  ");
	setcolor(GREEN);
	sprintf(text,"%d",p);
	outtextxy(460, 70, text);
	setcolor(RED);
	outtextxy(660, 70, "q  :  ");
	setcolor(GREEN);
	sprintf(text, "%d", q);
	outtextxy(720, 70, text);



	setcolor(RED);
	outtextxy(10, 110, "---------------------------------------------------------------------------------------------------------------------");


	n = p*q;
	totient = (p - 1)*(q - 1);
	printf("\nTotient(%d)\t:  %d\n", n, totient);
	printf("***************************");

	setcolor(RED);
	outtextxy(400, 150, "Totient  (");
	setcolor(GREEN);
	sprintf(text, "%d", n);
	outtextxy(539, 150, text);
	setcolor(RED);
	outtextxy(640, 150, ")     :");
	setcolor(GREEN);
	sprintf(text, "%d", totient);
	outtextxy(720, 150, text);

	setcolor(RED);
	outtextxy(10, 190, "---------------------------------------------------------------------------------------------------------------------");

	
	message = rand() % 101;
	printf("\nMessage\t\t:  %d\n", message);
	printf("***************************");

	setcolor(RED);
	outtextxy(400, 230, "Message");
	outtextxy(690, 230, ":");
	setcolor(GREEN);
	sprintf(text, "%d", message);
	outtextxy(720, 230, text);

	setcolor(RED);
	outtextxy(10, 270, "---------------------------------------------------------------------------------------------------------------------");


	e = prime_e[rand() % 10];
	while (gcd(totient, e) != 1)
	{
		e = prime_e[rand() % 10];
	}
	find_d(totient, e, &x, &y, &d);
	d = y;
	if (d>totient)
	{
		d = d%totient;
	}
	if (d<0)
	{
		d = d + totient;
	}
	printf("\n\nPublic Key : (%d   ,%d)\nPrivate Key: (%d ,%d)\n\n", e, n, d, n);


	setcolor(RED);
	outtextxy(400, 310, "Public Key");
	outtextxy(690, 310, ":  (");
	setcolor(GREEN);
	sprintf(text, "%d", e);
	outtextxy(740, 310, text);
	setcolor(RED);
	outtextxy(830, 310, ",");
	setcolor(GREEN);
	sprintf(text, "%d", n);
	outtextxy(850, 310, text);
	setcolor(RED);
	outtextxy(950, 310, ")");

	setcolor(RED);
	outtextxy(400, 340, "Private Key");
	outtextxy(690, 340, ":  (");
	setcolor(GREEN);
	sprintf(text, "%d", d);
	outtextxy(740, 340, text);
	setcolor(RED);
	outtextxy(830, 340, ",");
	setcolor(GREEN);
	sprintf(text, "%d", n);
	outtextxy(850, 340, text);
	setcolor(RED);
	outtextxy(950, 340, ")");

	setcolor(RED);
	outtextxy(10, 380, "---------------------------------------------------------------------------------------------------------------------");
	

	printf("***************************");
	encrypting = crypte(message, n, e);
	printf("\nEncrypted Message  :  %d", encrypting);
	decrypting = crypte(encrypting, n, d);
	printf("\nDecrypted Message  :  %d\n\n", decrypting);
	printf("***************************\n");
	printf("******TOLGA AKKAPULU*******\n");
	printf("***************************");

	setcolor(RED);
	outtextxy(400, 420, "Encrypted Message");
	outtextxy(690, 420, ":  ");
	setcolor(GREEN);
	sprintf(text, "%d", encrypting);
	outtextxy(740, 420, text);

	setcolor(RED);
	outtextxy(10, 460, "---------------------------------------------------------------------------------------------------------------------");

	setcolor(RED);
	outtextxy(400, 500, "Decrypted Message");
	outtextxy(690, 500, ":  ");
	setcolor(GREEN);
	sprintf(text, "%d", decrypting);
	outtextxy(740, 500, text);


	setcolor(RED);
	outtextxy(10, 540, "---------------------------------------------------------------------------------------------------------------------");


	outtextxy(10, 560, "****************************");
	setcolor(GREEN);     
	outtextxy(500, 560, "TOLGA AKKAPULU");
	setcolor(RED);
	outtextxy(820, 560, "****************************");

	getchar();
	return 0;
}