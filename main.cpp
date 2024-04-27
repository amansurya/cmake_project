#include <iostream>

int Array_Basics( void );
int String_Basics( void );
int Pointers_Basics( void ); 
int Functions_Basics( void ); 
int String_Assignment( void );
int main() {
// Call the functions
#ifdef CONFIG_ENABLE_MODULE_POINTERS
    Pointers_Basics();
#endif
#ifdef CONFIG_ENABLE_MODULE_ARRAYS
    Array_Basics();
    #ifdef CONFIG_ENABLE_MODULE_STRINGS
        String_Basics();
    #endif
    #ifdef CONFIG_ENABLE_MODULE_STRINGS_ASSIGNMENTS
        String_Assignment();
    #endif
#endif
#ifdef CONFIG_ENABLE_MODULE_FUNCTIONS
    Functions_Basics();
#endif

    return 0;
}
