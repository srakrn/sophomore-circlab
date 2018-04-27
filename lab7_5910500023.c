#include<stdio.h>
#include<limits.h>

int absVal(int x){
	int signBit = x >> 31;
	return (x ^ signBit) - signBit;
}

int whatIsByte(int x, int para){
	x = x << ((3-para) << 3) >> 24;
	/*
	x = x << ((7-para)*4);
	x = x >> ((para+1)*4);
	*/
	return x & 0xff;
}

int srlForced(int x, int para){
	return (x >> para) & ~(((0x1 << 31) >> para) << 1);
}

int oneCount(int x){
	int mask = 0x01010101;
	int res = 0;
	res += x & mask;
	res += (x >> 1) & mask;
	res += (x >> 2) & mask;
	res += (x >> 3) & mask;
	res += (x >> 4) & mask;
	res += (x >> 5) & mask;
	res += (x >> 6) & mask;
	res += (x >> 7) & mask;
	return (res +
		(res >> 8) +
		(res >> 16) +
		(res >> 24)
	) & 0x1f;
}

int isNumOneOdd(unsigned x){
	x = x ^ (x >> 16);
	x = x ^ (x >> 8);
	x = x ^ (x >> 4);
	x = x ^ (x >> 2);
	x = x ^ (x >> 1);
	return x & 0x1;
}

int largestNeg(){
	return 1 << 31;
}

int isFitable(int x, int para){
	int sign_bit = x & 0x80000000;
	int y = x << (32-para);
	return !(((sign_bit | y) >> (32-para)) ^ x);
}

int oppNum(int x){
	return ~x + 1;
}

int isGTZ(int x){
	return !(x >> 31) && (x);
}

int isLTE(int x, int y){
	return !((y-x) >> 31);
}

int main(){
	// Absolute function
	// We include `limits.h` to initialise limit values
	// for the datatypes. This will be useful for testing
	// interger boundaries.
	//
	// For absolute function, we test the following values:
	//	- Least integer with 0 as signing bit (0)
	//	- Least integer with 1 as signing bit (1)
	//	- Arbitary numbers (+-25)
	//	- Maximum and minimum values for integers.
	printf("absVal(0) = %d\n", absVal(0));
	printf("absVal(-1) = %d\n", absVal(-1));
	printf("absVal(25) = %d\n", absVal(25));
	printf("absVal(-25) = %d\n", absVal(-25));
	printf("absVal(INT_MIN) = %d\n", absVal(INT_MIN)); // Should overflow
	printf("absVal(INT_MAX) = %d\n", absVal(INT_MAX));

	// whatIsByte function
	// We test the given values for all possible bit extraction
	// (0th, 1st, 2nd, 3rd bit respectively). Then we test the bits for
	// the all-zero and all-ones bit.
	printf("whatIsByte(0xabcd5678, 0) = %x\n", whatIsByte(0xabcd5678, 0));
	printf("whatIsByte(0xabcd5678, 1) = %x\n", whatIsByte(0xabcd5678, 1));
	printf("whatIsByte(0xabcd5678, 2) = %x\n", whatIsByte(0xabcd5678, 2));
	printf("whatIsByte(0xabcd5678, 3) = %x\n", whatIsByte(0xabcd5678, 3));
	printf("whatIsByte(0xffffffff, 2) = %x\n", whatIsByte(0xffffffff, 2));
	printf("whatIsByte(0x00000000, 2) = %x\n", whatIsByte(0x00000000, 2));

	// whatIsByte function
	// We test the given values for all possible bit extraction
	// (0th, 1st, 2nd, 3rd bit respectively). Then we test the bits for
	// the all-zero and all-ones bit.
	printf("srlForced(0xabcd5678, 4) = %x\n", srlForced(0xabcd5678, 4));
	printf("srlForced(0xabcd5678, 8) = %x\n", srlForced(0xabcd5678, 8));
	printf("srlForced(0xabcd5678, 12) = %x\n", srlForced(0xabcd5678, 12));
	printf("srlForced(0xabcd5678, 16) = %x\n", srlForced(0xabcd5678, 16));
	printf("srlForced(0xabcd5678, 20) = %x\n", srlForced(0xabcd5678, 20));
	printf("srlForced(0xabcd5678, 24) = %x\n", srlForced(0xabcd5678, 24));

	// oneCount function
	printf("oneCount(0) = %d\n", oneCount(0));
	printf("oneCount(1) = %d\n", oneCount(1));
	printf("oneCount(3) = %d\n", oneCount(3));
	printf("oneCount(7) = %d\n", oneCount(7));
	printf("oneCount(15) = %d\n", oneCount(15));
	printf("oneCount(31) = %d\n", oneCount(31));

	// isNumOneOdd function
	// checks for some arbitary random numbers,
	// including 0 and 1 for the sake of simplicity.
	printf("isNumOneOdd(0) = %d\n", isNumOneOdd(0));
	printf("isNumOneOdd(1) = %d\n", isNumOneOdd(1));
	printf("isNumOneOdd(3) = %d\n", isNumOneOdd(3));
	printf("isNumOneOdd(7) = %d\n", isNumOneOdd(7));
	printf("isNumOneOdd(15) = %d\n", isNumOneOdd(15));
	printf("isNumOneOdd(31) = %d\n", isNumOneOdd(31));

	// largestNeg function
	// There should be no tests.
	printf("largestNeg() = %d\n", largestNeg());

	// isFitable function
	// testing with common overflow values for
	// 4 and 8 bit values.
	printf("isFitable(7, 4) = %d\n", isFitable(7, 4));
	printf("isFitable(8, 4) = %d\n", isFitable(8, 4));
	printf("isFitable(-8, 4) = %d\n", isFitable(-8, 4));
	printf("isFitable(127, 8) = %d\n", isFitable(127, 8));
	printf("isFitable(128, 8) = %d\n", isFitable(128, 8));
	printf("isFitable(-128, 8) = %d\n", isFitable(-128, 8));

	// isGTZ function
	// test on normal 0, 1, -1 values
	// and on minimum/maximum boundaries.
	printf("isGTZ(0) = %d\n", isGTZ(0));
	printf("isGTZ(-0) = %d\n", isGTZ(-0));
	printf("isGTZ(1) = %d\n", isGTZ(1));
	printf("isGTZ(-1) = %d\n", isGTZ(-1));
	printf("isGTZ(INT_MIN) = %d\n", isGTZ(INT_MIN));
	printf("isGTZ(INT_MAX) = %d\n", isGTZ(INT_MAX));

	// isLTE function
	// test on random values
	printf("isLTE(-846482446, -855515057) = %d\n", isLTE(-846482446, -855515057));
	printf("isLTE(451090591, -1586952027) = %d\n", isLTE(451090591, -1586952027));
	printf("isLTE(180692452, 2107776902) = %d\n", isLTE(180692452, 2107776902));
	printf("isLTE(-928701758, 417861639) = %d\n", isLTE(-928701758, 417861639));
	printf("isLTE(-717889023, 676265823) = %d\n", isLTE(-717889023, 676265823));
	printf("isLTE(842804344, -288158564) = %d\n", isLTE(842804344, -288158564));
	return 0;
}
