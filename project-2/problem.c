#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#define PASSWORD "ABCD1234!"
/*You need not worry about other include statements if at all any are missing */

void func1()
{
    char * data;
    char * dataBuffer = (char *)ALLOCA(100*sizeof(char));
    memset(dataBuffer, 'A', 100-1);
    dataBuffer[100-1] = '\0';
    data = dataBuffer - 8;
    {
        char source[100];
        memset(source, 'C', 100-1); 
        source[100-1] = '\0'; 
        strcpy(data, source); //  Accessing memory outside allocated block, could lead to segfault.
                              //  It overwrite the return address on the program stack and lead to make the program execution jump back
                              //  to an unknown location and program could exit with segfaul. 
        if(data != NULL) 
        {
            printf("%s\n", data);
        }
    }
}

void func2()
{
    char * data;
    data = NULL;
    data = (char *)calloc(100, sizeof(char));
    strcpy(data, "A String"); // No NULL check for data, in case calloc fails to allocate memory.
                              // This may cause segfault at this point.
    if(data != NULL) 
    {
        printf("%s\n", data);
    }
}

void func3()
{
    char * password;
    char passwordBuffer[100] = "";
    password = passwordBuffer;
    strcpy(password, PASSWORD);
    {
        HANDLE pHandle;
        char * username = "User";
        char * domain = "Domain";
        /* Let's say LogonUserA is a custon authentication function*/
        if (LogonUserA(
                    username,
                    domain,
                    //    Buffer overflow attack: passing a raw pointer to local variable passwordBuffer is risky.
                    //    Any malicious procedure call like LogonUserA can inject malicious payload into passwordBuffer and 
                    //    launch buffer overflow attack.
                    password,
                    &pHandle) != 0) 
        {
            printf("User logged in successfully.\n");
            CloseHandle(pHandle);
        }
        else
        {
            printf("Unable to login.\n");
        }
    }
}

static void func4()
{ // This looks okay.
    char * data;
    data = NULL;
    data = (char *)calloc(20, sizeof(char));
    if (data != NULL)
    {
        strcpy(data, "Initialize");
        if(data != NULL) 
        {
            printf("%s\n", data);
        }
        free(data);
    }
}

void func5() 
{
    int i = 0;
    do
    {
        printf("%d\n", i);
        i = (i + 1) % 256;
    } while(i >= 0); // Non-terminating loop. value of i will always between 0 to 255
}

void func6()
{
    char dataBuffer[100] = "";
    char * data = dataBuffer;
    printf("Please enter a string: ");
    if (fgets(data, 100, stdin) < 0) // fgets returns NULL (0) on failure and this comparision will never be true
    {
        printf("fgets failed!\n");
        exit(1);
    }
    if(data != NULL) 
    {
        printf("%s\n", data);
    }

}

void func7()
{
    char * data;
    data = "Fortify";
    data = NULL;

    // VULNERABLE: passing null pointer to printf could be a seg fault or undefined behaviour
    printf("%s\n", data);
}

int main(int argc, char * argv[])
{
    printf("Calling func1\n");
    func1();

    printf("Calling func2\n");
    func2();

    printf("Calling func3\n");
    func3();

    printf("Calling func4\n");
    func4();

    printf("Calling func5\n");
    func5();

    printf("Calling func6\n");
    func6();

    printf("Calling func7\n");
    func7();

    return 0;
}

