#ifndef ENCRYPTION_H
 #define ENCRYPTION_H
#endif

/* Headers that will be used */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


/* Custom Types */
#define result(s) printf("\nExecution code: %d [success!]\n", s)

#define exec_result(s) { if(s==0) result(s); else puts("<EXEC ERROR!>"); }
#define _(s) # s
#define nullptr (void*)NULL
#define new_string(s) calloc(s, sizeof(void*))

#define Integer8  uint8_t
#define Integer16 uint16_t
#define Integer32 uint32_t
#define String    const char*


/* Functions and types to be used */
static _Bool verifyStr ( char msg[] );
static _Bool encrypt   ( char msg[], uint8_t key_x, uint8_t key_y );
static _Bool decrypt   ( char msg[], uint8_t key_x, uint8_t key_y );
static _Bool tk_fEncrypt( FILE *p, String file_name);
static FILE *file_p=nullptr;
static Integer8 verifyArgs(int argc, char arg[] );
struct flag;

int main( int argc, char **argv )
{

  /*
   *
   * Verify if the program has some arguments, and look for what argument 
   * has been passed to program.
   * 
   */

    verifyArgs( argc, *argv);
    
    // String personalizada >:)
    String lol = new_string(1);
    lol = (const char*)"[conteudo da variavel aqui]";
    
    printf("Numero args: %d\nNome do programa: %s\n", argc, *argv);
    puts("VARIAVEL:");
    puts(lol);
    puts("");

    // const char *nome_prog = calloc(1, sizeof(strlen(*argv)+1)); // [TO VERIFY:y]
    // nome_prog = (const char*)argv;                              // [TO VERIFY:y]
    
    // printf("\n%s\n", nome_prog[2]);

    Integer8 exec_code;
    
    // Executes an encryption above word passed as parameter,
    // then returns your execution code, where 0(zero) means
    // sucess and 1 fault.
    #define _var 0x11
    printf("\nPHRASE: %s\n\n", "\"Mensagem a ser criptografada.\"");
    exec_code = encrypt("Mensagem a ser criptografada.", 0x05, 0x04); // Fix letter accentuation AFTER!!!
    
    if(exec_code == 0)
    {
        exec_result(exec_code);
    }
    else
    {
        exec_result(1);
        puts("Fail to encrypt string or file.");
    }
 
    return exec_code;

}

// FLAG of 1bit to true or false
typedef struct flag { Integer8 value: 1; } flag;

static _Bool encrypt( char msg[], uint8_t key_x, uint8_t key_y )
{

    String s; // read only variable :/ I'll make a dynamic after
    s = new_string(strlen(msg));
    char *e = new_string(strlen(msg));
    char en_tag[strlen(msg)];
    int verStr, i;

    verStr = verifyStr(msg);

    // Exception handling
    if( verStr == 1 )
    {
        fprintf(stderr, "Encryption error, maybe value passed has been invalid.\n");
        return 1;
    }    

    puts(_([HASH CRIPTOGRAFICA));
    
    // Encryption action
    for(i=0; i < strlen(msg); i++ )
    {
        // (msg[i]^key_x)>>key_y);
        //*(e+0) = msg[i] << 1;
        //printf("%p", *(e+i));]
        //printf("%c", ); // IF 'aeiou' == :
        en_tag[i] = (msg[i]^key_x)|key_y; // Function to encrypt
        en_tag[i] += 5;
        if(en_tag[i]=='%'||en_tag[i]=='k'||en_tag[i]=='K')
            en_tag[i] = ':';
        if(en_tag[i]=='z'+5)
            en_tag[i] = 'a';
        /*if(en_tag[i]=='e')
            en_tag[i] = '\r';*/
        while(en_tag[i]=='#')
            en_tag[i]^=20;
            
        printf("%c", en_tag[i]);
        
    } puts("");

    return 0;

}

static _Bool decrypt( char msg[], uint8_t key_x, uint8_t key_y )
{

    

    return 0;

}

static _Bool verifyStr( char msg[] )
{
    return (msg == nullptr) ? 1 : 0;
}

Integer8 verifyArgs( int argc, char arg[] )
{
    if(argc > 1 && arg != "--help")
    {
        puts("*Are you looking for some [help?]");
        puts("usage: progname --help");
        puts("note: this program does not accept aditional parameters yet.");
        
        return 1;
    }
}
