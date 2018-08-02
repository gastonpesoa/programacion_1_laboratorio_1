
#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

int optionMainMenu(void);
int optionListSelect(void);
int optionModifyMenu(void);

void cleanStdin(void);
void clearScreen(void);
void pause(char *pauseMessage);
char confirm(char confirmMessage[]);

int getInt(char mensaje[]);
float getFloat(char mensaje[]);
char getChar(char mensaje[]);

int esNumerico(char str[]);
int esNumericoFlotante(char str[]);
int esSoloLetras(char str[]);
int esAlfaNumerico(char str[]);
int esTelefono(char str[]);
int esArchivo(char str[]);
int esMail(char str[]);

void getString(char mensaje[],char input[]);
void getStringSpace(char mensaje[], char input[]);
int getStringNumeros(char mensaje[],char input[]);
int getStringNumerosFlotantes(char mensaje[],char input[]);
int getStringLetras(char mensaje[],char input[]);
int getStringAlfanumerico(char mensaje[],char input[]);
int getStringArchivo(char mensaje[],char input[]);
int getStringMail(char mensaje[],char input[]);

int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);
int getValidFloat(char requestMessage[],char errorMessage[],float lowLimit, float hiLimit);
void getValidString(char requestMessage[],char errorMessage[], char input[]);
void getValidStringAlfanumerico(char requestMessage[],char errorMessage[], char input[]);
void getValidStringArchivo(char requestMessage[],char errorMessage[], char input[]);
void getValidStringMail(char requestMessage[],char errorMessage[], char input[]);

void capitalize(char input[]);
void capitalizeFirstWord(char input[]);
int validateStrLenght(char input[],int lowLimit,int hiLimit);

#endif // INPUT_H_INCLUDED

