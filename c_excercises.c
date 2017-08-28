//---------------------------------------------------------------------------
//TEST1  @Parasyti reiksme ir paaiskinti
//---------------------------------------------------------------------------
void testas(void){

	char *ptr1 = NULL; // initialize pointers
	char *ptr2 = NULL;
	
	char var1 = 5; // initialize variables
	char var2 = 8;
	
	unsigned int result1 = 0; // initialize result variable
	
	ptr1 = &var1; // set ptr1 to point to address of var1
	
	ptr2 = ptr1; // set ptr2 equal to ptr1 (address of var1)
	
	var1 -= 2; // subtract 2 from var1 (var1 = 3)
	
	result1 = (*ptr2)+6; // set result1 to dereferenced value of ptr2 (var1) and add 6 (3 + 6 = 9)

	// Kokia yra result1 reiksme? 
	// result1: 9

	return 1;
	
}

//---------------------------------------------------------------------------
//TEST2  @Parasyti reiksme ir paaiskinti
//---------------------------------------------------------------------------

int *GetArrayMember(unsigned int index); // function prototype
int temp_buff[10]={5,6,8,7,5,6,8,2,6,'\0'}; // initialize buffer

void testas2(void){
  
	unsigned int var1 = 200; // initialize variables
	unsigned int var2 = 5;

	int *ptr1 = &var1; // initialize and set ptr1 to address of var1
	int *ptr2 = &var2; // initialize and set ptr2 to address of var2
		
	unsigned int result1 = 0; // initialize result variables
	unsigned int result2 = 0;
	
	*ptr2 = 10; // set var2 (variable stored at address pointed by ptr2) to 10 (var2 = 10)

	(*ptr1)++; // increment var1 (variable stored at address pointed by ptr1) (var1 = 201)
	
	result1 = (*ptr1)*(*ptr2); // set result1 to product of variables pointed by ptr1 (var1) and ptr2 (var2) (result1 = 10 * 201)
	
	// Kokia yra result1 reiksme? 
	// result1: 2010
	
	ptr1 = GetArrayMember(3); // set pointer to address of fourth member of temp_buff

	*ptr2 = *ptr1; // set var2 to temp_buff[3]

	result2++; // increment result2 (result2 = 1)
	
	// Kokia yra var2 reiksme? 
	// var2: 7
	
	return 1;

}


int *GetArrayMember(unsigned int index){	

	return &temp_buff[index]; // return pointer to address of [index] member of temp_buff
	
}

//---------------------------------------------------------------------------
//TEST3 Rasti klaida/klaidas, reiksme, paaiskinti.
//---------------------------------------------------------------------------
	
void testas3(void){

	unsigned int var1 = 127; // initialize variable (4 bytes long)

	char *ptr1; // declare pointer (points to a variable 1 byte long)

	unsigned int result1 = 0; // initialize variable (4 bytes long)

	ptr1 = (char*)&var1; // type cast address of var1 to char* and set it to ptr1

	(*ptr1)++; // increment the value pointed to by ptr1 (var1). This causes an overflow (*ptr1 == -127)

	result1 = *ptr1; // set result to the value 
	
	// Kokia yra result1 reiksme? 
	// result1: 4294967168

	// klaida: negalima inkrementuot type castinto i kita tipa pointerio (neapibreztas elgesys)

	return 1;

}
	
	
//---------------------------------------------------------------------------
//TEST4 Rasti klaida/klaidas, OPTIMIZUOTI koda, paaiskinti
//---------------------------------------------------------------------------
void testas4(void){

	// char tmp_buff[7]={1,2,3,4,5,6,7};
	char tmp_buff[8] = {1,2,3,4,5,6,7,'\0'}; // initialize buffer

	unsigned char i = 0; // set increment variable

	//Isprintinam visus buferio skaicius 
	// printf("Val:%d\r\n",tmp_buff[i]);
	// i = i+1;
	// printf("Val:%d\r\n",tmp_buff[i]);
	// i = i+1;
	// printf("Val:%d\r\n",tmp_buff[i]);
	// i = i+1;
	// printf("Val:%d\r\n",tmp_buff[i]);
	// i = i+1;
	// printf("Val:%d\r\n",tmp_buff[i]);
	// i = i+1;
	// printf("Val:%d\r\n",tmp_buff[i]);
	// i = i+1;
	// printf("Val:%d\r\n",tmp_buff[i]);

	//Isvalome buferi
	// tmp_buff[i] = 0;
	// i = i+1;
	// tmp_buff[i] = 0;
	// i = i+1;
	// tmp_buff[i] = 0;
	// i = i+1;
	// tmp_buff[i] = 0;
	// i = i+1;
	// tmp_buff[i] = 0;
	// i = i+1;
	// tmp_buff[i] = 0;
	// i = i+1;
	// tmp_buff[i] = 0;

	//Uzpildome buferi skaiciumi 10
	// tmp_buff[i] = 10;
	// i = i+1;
	// tmp_buff[i] = 10;
	// i = i+1;
	// tmp_buff[i] = 10;
	// i = i+1;
	// tmp_buff[i] = 10;
	// i = i+1;
	// tmp_buff[i] = 10;
	// i = i+1;
	// tmp_buff[i] = 10;
	// i = i+1;
	// tmp_buff[i] = 10;
	
	while(i < 7) {
		printf("Val:%d\r\n", tmp_buff[i]); // Isprintinam visus buferio skaicius
		// tmp_buff[i] = 0; // Isvalome buferi
		tmp_buff[i++] = 10; // Uzpildome buferi skaiciumi 10
	}
	//Palyginam pirmus 3 skaicius su musu norimu skaiciumi ir ivykdom salyga
	// if(tmp_buff[0] == 10 && tmp_buff[1] == 10 && tmp_buff[2] == 10){

	// 	printf("Salyga ivykdyta\r\n");

	// }else{

	// 	printf("Salyga neivykdyta\r\n");    

	// }
	(tmp_buff[0] == 10 && tmp_buff[1] == tmp_buff[0] && tmp_buff[2] == tmp_buff[0]) ? (printf("Salyga ivykdyta\r\n")) : (printf("Salyga neivykdyta\r\n")); 

	return 1;

}
