//-----------------------------------------------------------------------
// Koks sios strukturos dydis 32Bit ARM architekturoje?
//-----------------------------------------------------------------------
typedef struct strucTest{
    
    unsigned int Value1; 	// 4 bytes
    unsigned char Value2;   // 1 byte
    uint8_t Value3; 		// 1 byte
    						// total: 6 bytes
};

//-----------------------------------------------------------------------
// Identifikuoti klaida/klaidas/trukumus?
// Pataisymo/prevencijos pasiulymai (min. 2 pasiulymai)
// KOkia 5tojo buferio elemento galutine reiksme?
//-----------------------------------------------------------------------
void func1(void) {
    
    char *pnt1 = NULL;
    const unsigned char FillWithThis = '5';
    
    pnt1 = malloc(128);
    
    memset(pnt1, FillWithThis, sizeof(pnt1));
    
    pnt[5] = pnt[5] + 20; // pnt -> pnt1
    pnt+=5; 			  // pnt -> pnt1
    *pnt -= 10; 		  // pnt -> pnt1
    // *pnt1 == 63
    // pasiulymai:
    // 1) nestumdyt pointerio pnt1 reiksmes (line 27)
    // 2) nenaudot misrios sintakses (line 26 / line 28)
    // 3) suvienodint buferio ir turinio tipus
}

//-----------------------------------------------------------------------
// Identifikuoti klaida/klaidas/trukumus?
// Pataisymo/prevemcijos pasiulymai (min. 2 pasiulymai)
//-----------------------------------------------------------------------
void Func_2(void){
    
    unsigned char Buffer[12]; // Buffer[12] -> Buffer[19] (16 raidziu + 2 simboliai + 1 uzdarymui)
    const char FillWithThis = "ABCDEFGHJKLMNOPR"; // char -> char*
    
    sprintf(Buffer,"%s\r\n",FillWithThis);
    // pasiulymai:
    // 1) nepildyti buferio papildomais simboliais sprintf funkcijoje (\r\n)
    // 2) nepildyti unsigned char bufferio neapibreztu char turiniu (suvienodinti tipus)
}


//-----------------------------------------------------------------------
// Pabaigti parasyti funkcija, kuri pakeicia kuri nors viena 
// is strukturos elementu ir grazina jo reiksme
//-----------------------------------------------------------------------
typedef struct /*strucTestB*/{

    unsigned int Value1;
    unsigned int Value2;
    unsigned int Value3;
    unsigned int Value4;
    
} strucTestB;

strucTestB TestBStructure;

void InitStruct(void){

    TestBStructure.Value1 = 1;
    TestBStructure.Value2 = 2;
    TestBStructure.Value3 = 3;
    TestBStructure.Value4 = 4;
    
}


unsigned int ReturnMeItem(strucTestB* someStruct){
    
    someStruct->Value1 = 6;
   
    return someStruct->Value1;
    
}

//-----------------------------------------------------------------------
// Parasyti funkcija, kuri patikrina "Value1" n-taji bita, jeigu tas bitas yra 1, 
// ji padaro 0 neliesdamas kitu bituku ir grazina galutine reiksme
//-----------------------------------------------------------------------
unsigned int Value1 = /*3FF*/0x3FF;


unsigned int BitChanger(unsigned int value, unsigned int bitToCheck) {
    
    if(value & (1 << bitToCheck)) {
    	value &= ~(1 << bitToCheck);
    }
    
    return value;
}


//-----------------------------------------------------------------------
// Parasyti funkcija, kuri sukeicia vietomis pateiktu kintamuju reiksmes
//-----------------------------------------------------------------------
unsigned int VSwapA = 25;
unsigned int VSwapB = 6589;

void SwapThoseValues(unsigned int a, unsigned int b){
    unsigned int temp;

    temp = a;
    a = b;
    b = temp;
}
