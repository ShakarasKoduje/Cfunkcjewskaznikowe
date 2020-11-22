#include <stdio.h>

char * func1(char *a) {
    *a = 'b';
    return a;
}

char * func2(char *a) {
    *a = 'c';
    return a;
}
int * func3() {
    printf("Funkcja 3\n");
    return 0;
    
}
int * func4() {
    printf("Funckja 4\n");
    return 0;
    
}
int func5() {
    printf("Funkcja 5\n");
    return 0;
    
}
int func6() {
    printf("Funckja 6\n");
    return 0;
    
}
int main() {
    char a = 'a';
    /* declare array of function pointers
     * the function pointer types are char * name(char *)
     * A pointer to this type of function would be just
     * put * before name, and parenthesis around *name:
     *   char * (*name)(char *)
     * An array of these pointers is the same with [x]
     */
    char * (*functions[2])(char *) = {func1, func2};
    int * (*funkcje[2])() = {func3, func4};
    int (*funkcje2[2])() = {func5, func6};
    int (*foo)();
    printf("%c, ", a);
    /* the functions return a pointer, so I need to deference pointer
     * Thats why the * in front of the parenthesis (in case it confused you)
     */
    printf("%c, ", *(*functions[0])(&a)); 
    printf("%c\n", *(*functions[1])(&a));
    *(*funkcje[0])();
    foo = func5;
    funkcje2[1] = foo;
    *(*funkcje[1])();
    (*funkcje2[0])();
    (*funkcje2[1])();

    a = 'a';
    /* creating 'name' for a function pointer type
     * funcp is equivalent to type char *(*funcname)(char *)
     */
    //typedef char *(*funcp)(char *);
    /* Now the declaration of the array of function pointers
     * becomes easier
     */
    //funcp functions2[2] = {func1, func2};

    //printf("%c, ", a);
    //printf("%c, ", *(*functions2[0])(&a));
    //printf("%c\n", *(*functions2[1])(&a));

    return 0;
}